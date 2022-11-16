#include "main_controller.h"

main_controller::main_controller(QObject *parent) :
  QObject(parent),
  users(new user_db()), rooms(new room_db()), active_user(nullptr),
  login_window(nullptr), main_window(nullptr)
{
  // RANDOM USERS
  users->add(new user("diego", "diego"));
  users->add(new user("pippo", "pippo"));
  users->add(new user("trex", "trex"));
  users->add(new user("matteo", "matte0"));
  users->add(new user("goku", "goku"));

  // RANDOM ROOMS
  rooms->add(new room("prova 1", {"diego", "pippo"}));
  rooms->add(new room("tutti", {"diego", "pippo", "trex", "matteo", "goku"}));
  rooms->add(new room("la prova del cuoco", {"diego", "pippo","trex", "matteo"}));
  rooms->add(new room("DBZ", {"diego", "goku"}));
  rooms->add(new room("la fattoria", {"trex", "goku", "diego"}));
}

main_controller::~main_controller() {
  delete users;
  delete rooms;
  delete login_window;
  delete main_window;
}

void main_controller::exec(){ show_login(); }

// SLOTS - SHOW VIEWS
void main_controller::show_login() {
  if(main_window) close_main();
  login_window = new login_view();

  connect(login_window,SIGNAL(event_close_login()),this,SLOT(close_login()));
  connect(login_window,SIGNAL(event_login_user(QString,QString)),this,SLOT(login_user(QString,QString)));
  connect(login_window,SIGNAL(event_register_user(QString,QString)),this,SLOT(register_user(QString,QString)));

  login_window->show();
}
void main_controller::show_main() {
  main_window = new main_view(active_user);

  connect(main_window,SIGNAL(event_show_room_info(room*)),this,SLOT(show_room_info(room*)));
  connect(main_window,SIGNAL(event_forward_entry(entry)),this,SLOT(show_forward_entry(entry)));

  connect(main_window,SIGNAL(event_fetch_by_date(room*,QDateTime,QDateTime)),this,SLOT(fetch_by_date(room*,QDateTime,QDateTime)));
  connect(main_window,SIGNAL(event_fetch_by_type(room*,entry_type)),this,SLOT(fetch_by_type(room*,entry_type)));
  connect(main_window,SIGNAL(event_fetch_by_text(room*,QString)),this,SLOT(fetch_by_text(room*,QString)));

  connect(main_window,SIGNAL(event_leave_room(room*)),this,SLOT(leave_room(room*)));
  connect(main_window,SIGNAL(event_delete_entry(room*,entry*)),this,SLOT(delete_entry(room*,entry*)));

  connect(main_window,SIGNAL(event_fetch_user_rooms()),this,SLOT(fetch_user_rooms()));
  connect(main_window,SIGNAL(event_fetch_room_entries(room*)),this,SLOT(fetch_room_entries(room*)));

  connect(main_window,SIGNAL(event_logout()),this,SLOT(show_login()));
  connect(main_window,SIGNAL(event_quit()),this,SLOT(close_main()));

  connect(main_window,SIGNAL(event_show_create_room()),this,SLOT(show_create_room()));
  connect(main_window,SIGNAL(event_show_user_profile()),this,SLOT(show_user_profile()));

  connect(main_window,SIGNAL(event_send_text(room*,QString,entry*)),this,SLOT(send_text(room*,QString,entry*)));
  connect(main_window,SIGNAL(event_send_file(room*,QString,entry*)),this,SLOT(send_file(room*,QString,entry*)));
  connect(main_window,SIGNAL(event_send_location(room*,QString,QString,entry*)),this,SLOT(send_location(room*,QString,QString,entry*)));
  connect(main_window,SIGNAL(event_send_contact(room*,QString,QString,entry*)),this,SLOT(send_contact(room*,QString,QString,entry*)));

  fetch_user_rooms();
  main_window->show();
}
void main_controller::show_forward_entry(const entry& e) const {
  forward_view* forward_window = new forward_view(new room_list_model(rooms->get_by_member(active_user->get_username())),e);
  connect(forward_window,SIGNAL(event_forward_to(room*,entry)),this,SLOT(forward_entry(room*,entry)));
  forward_window->exec();
}
void main_controller::show_create_room() const {
  create_room_view* create_room_window = new create_room_view(new user_list_model(users->get_all_but(active_user->get_username())));
  connect(create_room_window,SIGNAL(event_create_room(QString,QStringList)),this,SLOT(create_room(QString,QStringList)));
  create_room_window->exec();
}
void main_controller::show_user_profile() const {
  profile_view* account_window = new profile_view(*active_user);
  connect(account_window,SIGNAL(event_update_password(QString)),this,SLOT(update_password(QString)));
  account_window->exec();

}
void main_controller::show_room_info(room* r) const {
  room_info_view* room_info_window = new room_info_view(r);
  connect(room_info_window,SIGNAL(event_update_room_name(room*,QString)),this,SLOT(update_room_name(room*,QString)));
  room_info_window->exec();
}
void main_controller::close_login() {
  login_window->close();
  login_window = nullptr;
}
void main_controller::close_main() {
  main_window->close();
  main_window = nullptr;
}

// SLOTS - LOGIN ACTIONS
void main_controller::login_user(const QString &username, const QString &password) {
  active_user = users->validate(username.toStdString(), password.toStdString());
  if (active_user){
      close_login();
      show_main();
    }
  else{
      delete active_user;
      login_window->set_error("The username or password did not match");
    }
}
void main_controller::register_user(const QString &username, const QString &password) {
  active_user = new user(username.toStdString(), password.toStdString());
  try{
    if(users->add(active_user)){
        close_login();
        show_main();
      }
    else{
        delete active_user;
        login_window->set_error("This username has already been taken");
      }
  }
  catch(log_error l){
    login_window->set_error(QString::fromStdString(l.get_error()));
  }
}

// SLOTS - UPDATE MAIN VIEW
void main_controller::fetch_user_rooms() const {
  main_window->load_rooms(new room_list_model(rooms->get_by_member(active_user->get_username())));
}
void main_controller::fetch_room_entries(room* r) const {
  main_window->load_entries(new entry_list_model(r->get_all_entries()));
}
void main_controller::fetch_by_type(room* r, entry_type t) const {
  main_window->load_entries(new entry_list_model(r->get_by_type(t)));
}
void main_controller::fetch_by_text(room* r, const QString& text) const {
  main_window->load_entries(new entry_list_model(r->get_by_text(text.toStdString())));
}
void main_controller::fetch_by_date(room* r, const QDateTime& start, const QDateTime& end) const {
  main_window->load_entries(new entry_list_model(r->get_by_date(start.toTime_t(), end.toTime_t())));
}

// SLOTS - ROOM ACTIONS
void main_controller::update_room_name(room* r, const QString& s) const{
  r->set_name(s.toStdString());
}
void main_controller::update_password(const QString& pw) const{
  active_user->set_password(pw.toStdString());
}
void main_controller::create_room(const QString &name,const QStringList& members) const {
  std::vector<std::string> vs;
  for(auto i = members.begin(); i != members.end(); i++)
    vs.push_back(i->toStdString());

  vs.push_back(active_user->get_username());
  rooms->add(new room(name.toStdString(), vs));
}
void main_controller::leave_room(room* r) const {
  r->remove_member(active_user->get_username());
}

// SLOTS - ENTRY ACTIONS
void main_controller::send_text(room* r, const QString& content, entry* reply) const {
  r->write_text_message(active_user->get_username(), content.toStdString(), reply ? reply->get_id() : 0);
}
void main_controller::send_contact(room* r, const QString& name, const QString& number, entry* reply) const {
  r->write_contact_message(active_user->get_username(), name.toStdString(), number.toStdString(), reply ? reply->get_id() : 0);
}

void main_controller::send_location(room* r, const QString& lat, const QString& lon, entry* reply) const {
  r->write_location_message(active_user->get_username(), std::atof(lat.toStdString().c_str()), std::atof(lon.toStdString().c_str()), reply ? reply->get_id() : 0);
}
void main_controller::send_file(room* r, const QString &path, entry* reply) const {
  QFileInfo f(path);
  if (f.exists()){
      QString ext = f.suffix();
      if(ext == "png" || ext == "gif" || ext == "jpg")
        r->write_image_file(active_user->get_username(), path.toStdString(), reply ? reply->get_id() : 0);
      else
        r->write_generic_file(active_user->get_username(), path.toStdString());
    }
  else main_window->show_error("ERROR: Invalid file, operation skipped");
}
void main_controller::forward_entry(room* r, const entry& e) const {
  r->forward_message(static_cast<const message_entry*>(&e));
}
void main_controller::delete_entry(room* r, entry* e) const {
  r->erase(*e);
}
