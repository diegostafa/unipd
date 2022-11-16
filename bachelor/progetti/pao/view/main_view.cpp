#include "main_view.h"

main_view::main_view(const user* current_user) :
  active_user(current_user), active_room(nullptr), active_entry(nullptr),
  room_source(nullptr), entry_source(nullptr),
  proxy_room(new QSortFilterProxyModel(this)), entry_delegate(new entry_list_delegate(this)) {
  setWindowTitle("Grammer");
  resize(900,600);
  setMinimumSize(900,600);

  create_widgets();
  setup_gui_hierarchy();
  setup_menus();
  setup_properties();
  setup_styles();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

main_view::~main_view()
{
  delete create_room_btn;
  delete search_room_ln;
  delete rooms_ls;
  delete user_profile_tbtn;

  delete entries_ls;
  delete send_btn;
  delete in_reply_to_lb;
  delete text_ln;
  delete more_entries_tbtn;

  delete room_action_wdg;
  delete active_room_btn;
  delete action_room_tbtn;

  delete entry_action_wdg;
  delete active_entry_lb;
  delete preview_btn;
  delete forward_btn;
  delete delete_btn;
  delete cancel_btn;

  delete room_source;
  delete entry_source;
}

void main_view::show_error(const QString& err) const{
  QMessageBox msg;
  msg.setText(err);
  msg.exec();
}

// PRIVATE - GUI
void main_view::create_widgets(){
  create_room_btn = new QPushButton();
  search_room_ln = new QLineEdit();
  rooms_ls = new QListView();
  user_profile_tbtn = new QToolButton();

  entries_ls = new QListView();
  send_btn = new QPushButton();
  in_reply_to_lb = new QLabel();
  text_ln = new QLineEdit();
  more_entries_tbtn = new QToolButton();

  // room actions
  room_action_wdg = new QWidget();
  active_room_btn = new QPushButton();
  action_room_tbtn = new QToolButton();

  // entry actions
  entry_action_wdg = new QWidget();
  active_entry_lb = new QLabel();
  preview_btn = new QPushButton();
  forward_btn = new QPushButton();
  delete_btn = new QPushButton();
  cancel_btn = new QPushButton();
}
void main_view::setup_gui_hierarchy(){
  // layouts definition
  QHBoxLayout* main_hl = new QHBoxLayout();
  QVBoxLayout* left_vl = new QVBoxLayout();
  QHBoxLayout* search_room_hl = new QHBoxLayout();
  QHBoxLayout* system_hl = new QHBoxLayout();
  QVBoxLayout* right_vl = new QVBoxLayout();
  QHBoxLayout* send_hl = new QHBoxLayout();
  QSpacerItem* settings_spacer = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
  QHBoxLayout* action_room_hl = new QHBoxLayout();
  QHBoxLayout* action_entry_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_hl);
  main_hl->addLayout(left_vl);
  left_vl->addLayout(search_room_hl);
  search_room_hl->addWidget(create_room_btn);
  search_room_hl->addWidget(search_room_ln);
  left_vl->addWidget(rooms_ls);
  left_vl->addLayout(system_hl);
  system_hl->addWidget(user_profile_tbtn);
  system_hl->addSpacerItem(settings_spacer);
  main_hl->addLayout(right_vl);
  right_vl->addWidget(room_action_wdg);
  room_action_wdg->setLayout(action_room_hl);
  action_room_hl->addWidget(active_room_btn);
  action_room_hl->addWidget(action_room_tbtn);
  right_vl->addWidget(entry_action_wdg);
  entry_action_wdg->setLayout(action_entry_hl);
  action_entry_hl->addWidget(in_reply_to_lb);
  action_entry_hl->addWidget(preview_btn);
  action_entry_hl->addWidget(forward_btn);
  action_entry_hl->addWidget(delete_btn);
  action_entry_hl->addWidget(cancel_btn);
  //right_vl->addWidget(img_viewer);
  right_vl->addWidget(entries_ls);
  right_vl->addLayout(send_hl);
  send_hl->addWidget(send_btn);
  send_hl->addWidget(text_ln);
  send_hl->addWidget(more_entries_tbtn);
}
void main_view::setup_properties() const{
  create_room_btn->setText("New room");
  search_room_ln->setPlaceholderText("Search room...");
  search_room_ln->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,10}")));
  text_ln->setPlaceholderText("Type your message here...");
  user_profile_tbtn->setText(QString::fromStdString(active_user->get_username()));
  user_profile_tbtn->setPopupMode(QToolButton::InstantPopup);
  user_profile_tbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  action_room_tbtn->setPopupMode(QToolButton::InstantPopup);
  active_room_btn->setFont(QFont("Liberation sans", 10, QFont::Bold));
  more_entries_tbtn->setText("Attach");
  more_entries_tbtn->setPopupMode(QToolButton::InstantPopup);
  more_entries_tbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  preview_btn->setText("Preview");
  forward_btn->setText("Forward");
  delete_btn->setText("Delete");
  cancel_btn->setText("Cancel");
  rooms_ls->setSelectionMode(QAbstractItemView::SingleSelection);
  rooms_ls->setStyleSheet("QListView::item { height: 80px;} QListView{font-size: 14px; }");
  send_btn->setText("Send");
  entries_ls->setContextMenuPolicy(Qt::CustomContextMenu);
  entries_ls->setItemDelegate(entry_delegate);
  entries_ls->setWordWrap(true);
  entries_ls->setUniformItemSizes(false);
  entries_ls->setDragEnabled(false);
  entries_ls->setSelectionRectVisible(false);
  in_reply_to_lb->setFont(QFont("Liberation sans", 10, QFont::Bold));
  entry_action_wdg->hide();
  room_action_wdg->hide();
}
void main_view::setup_styles() const{
  // icons
  send_btn->setIcon(QIcon(QPixmap(":/send.png").scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation )));
  more_entries_tbtn->setIcon(QIcon(QPixmap(":/attach.png").scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation )));
  action_room_tbtn->setIcon(QIcon(QPixmap(":/more.png").scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation )));
  create_room_btn->setIcon(QIcon(QPixmap(":/room.png").scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation )));
  user_profile_tbtn->setIcon(QIcon(QPixmap(":/profile.png").scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation )));
}
void main_view::setup_menus() const{

  // user menu
  QMenu* power_mn = new QMenu();
  QAction* account_act = new QAction("Profile",power_mn);
  QAction* logout_act = new QAction("Logout",power_mn);
  QAction* quit_act = new QAction("Quit",power_mn);
  power_mn->addAction(account_act);
  power_mn->addAction(logout_act);
  power_mn->addAction(quit_act);
  user_profile_tbtn->setMenu(power_mn);

  // room menu
  QMenu* room_mn = new QMenu();
  QAction* refresh_act = new QAction("Refresh", room_mn);
  QAction* leave_act = new QAction("Leave room", room_mn);
  QAction* sort_act = new QAction("Sort", room_mn);
  QMenu* filter_mn = new QMenu("Filter", room_mn);
  QAction* by_text_act = new QAction("By text", filter_mn);
  QAction* by_date_act = new QAction("By date", filter_mn);
  QMenu* by_type_mn = new QMenu("By type", filter_mn);
  QAction* tm_act = new QAction("Text", by_type_mn);
  QAction* cm_act = new QAction("Contact", by_type_mn);
  QAction* lm_act = new QAction("Location", by_type_mn);
  QAction* fm_act = new QAction("File", by_type_mn);
  QAction* im_act = new QAction("Image", by_type_mn);
  room_mn->addAction(sort_act);
  room_mn->addMenu(filter_mn);
  filter_mn->addAction(by_text_act);
  filter_mn->addAction(by_date_act);
  filter_mn->addMenu(by_type_mn);
  by_type_mn->addAction(tm_act);
  by_type_mn->addAction(cm_act);
  by_type_mn->addAction(lm_act);
  by_type_mn->addAction(fm_act);
  by_type_mn->addAction(im_act);
  room_mn->addAction(refresh_act);
  room_mn->addAction(leave_act);

  action_room_tbtn->setMenu(room_mn);

  // entry menu
  QMenu* entries_mn = new QMenu();
  QAction* file_act = new QAction("File",entries_mn);
  QAction* location_act = new QAction("Location",entries_mn);
  QAction* contact_act = new QAction("Contact",entries_mn);
  entries_mn->addAction(file_act);
  entries_mn->addAction(location_act);
  entries_mn->addAction(contact_act);
  more_entries_tbtn->setMenu(entries_mn);

  // menu connections
  connect(account_act,SIGNAL(triggered(bool)),this,SLOT(action_show_profile()));
  connect(logout_act,SIGNAL(triggered(bool)),this,SLOT(action_logout()));
  connect(quit_act,SIGNAL(triggered(bool)),this,SLOT(action_quit()));

  connect(refresh_act,SIGNAL(triggered(bool)),this,SLOT(action_refresh_room()));
  connect(sort_act,SIGNAL(triggered(bool)),this,SLOT(action_sort_entries()));
  connect(leave_act,SIGNAL(triggered(bool)),this,SLOT(action_leave_room()));
  connect(by_text_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_text()));
  connect(by_date_act,SIGNAL(triggered(bool)),this,SLOT(show_date_input()));
  connect(tm_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_type_text()));
  connect(cm_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_type_contact()));
  connect(lm_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_type_location()));
  connect(fm_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_type_file()));
  connect(im_act,SIGNAL(triggered(bool)),this,SLOT(action_fetch_by_type_image()));

  connect(file_act,SIGNAL(triggered(bool)),this,SLOT(show_send_file()));
  connect(location_act,SIGNAL(triggered(bool)),this,SLOT(show_send_location()));
  connect(contact_act,SIGNAL(triggered(bool)),this,SLOT(show_send_contact()));

}
void main_view::setup_connections()const{
  connect(active_room_btn,SIGNAL(clicked()),this,SLOT(action_show_room_info()));
  connect(forward_btn,SIGNAL(clicked()),this,SLOT(action_forward_entry()));
  connect(preview_btn,SIGNAL(clicked()),this,SLOT(action_image_view()));
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(action_remove_entry_focus()));
  connect(delete_btn,SIGNAL(clicked()),this,SLOT(action_delete_entry()));
  connect(cancel_btn,SIGNAL(clicked()),entries_ls,SLOT(clearSelection()));

  connect(create_room_btn,SIGNAL(clicked()),this,SLOT(action_show_create_room()));
  connect(send_btn,SIGNAL(clicked()),this,SLOT(action_send_text()));
  connect(search_room_ln,SIGNAL(textChanged(QString)),proxy_room,SLOT(setFilterFixedString(QString)));
  connect(rooms_ls,SIGNAL(clicked(QModelIndex)),this,SLOT(action_select_room(QModelIndex)));
  connect(entries_ls,SIGNAL(clicked(QModelIndex)),this,SLOT(action_select_entry(QModelIndex)));
}
void main_view::update_room_info() const{
  if(active_room)
    active_room_btn->setText(QString::fromStdString(active_room->get_name() + " - " + std::to_string(active_room->num_members()) + " members"));
  else
    active_room_btn->setText("");
}

// OVERRIDE
void main_view::closeEvent(QCloseEvent *event){
  if (event->spontaneous()) emit event_quit();
  else QWidget::closeEvent(event);
}

// SLOTS - MAIN VIEW STATE
void main_view::load_rooms(room_list_model* src) {
  if(room_source) delete room_source;
  room_source = src;
  proxy_room->setSourceModel(room_source);
  rooms_ls->setModel(proxy_room);
}
void main_view::load_entries(entry_list_model* src) {
  if(entry_source) delete entry_source;
  entry_source = src;
  entries_ls->setModel(entry_source);
}
void main_view::enable_entry_actions() const {
  disable_room_actions();
  entry_action_wdg->show();
  bool del = active_entry->is_message() && static_cast<message_entry*>(active_entry)->get_sender() == active_user->get_username();
  if(del) delete_btn->show();
  else delete_btn->hide();
  in_reply_to_lb->setText(QString::fromStdString("Replying to #" + std::to_string(active_entry->get_id())));
}
void main_view::disable_entry_actions() const {
  enable_room_actions();
  entry_action_wdg->hide();
  in_reply_to_lb->setText("");
}

void main_view::enable_room_actions() const {
  room_action_wdg->show();
}
void main_view::disable_room_actions() const {
  room_action_wdg->hide();
}


// SLOTS - USER INPUT VIEWS
void main_view::show_send_file() const{
  if(active_room) {
      QString p = QFileDialog::getOpenFileName();
      if(!p.isEmpty())
        {
          send_file_view* file_window = new send_file_view(p);
          connect(file_window,SIGNAL(event_send_file(QString)),this,SLOT(action_send_file(QString)));
          file_window->exec();
        }
    }
  else show_error("Create and/or select a room to start");
}
void main_view::show_send_location() const{
  if(active_room) {
      send_location_view* location_window = new send_location_view();
      connect(location_window,SIGNAL(event_send_location(QString,QString)),this,SLOT(action_send_location(QString,QString)));
      location_window->exec();
    }
  else show_error("Create and/or select a room to start");
}
void main_view::show_send_contact() const{
  if(active_room) {
      send_contact_view* contact_window = new send_contact_view();
      connect(contact_window,SIGNAL(event_send_contact(QString,QString)),this,SLOT(action_send_contact(QString,QString)));
      contact_window->exec();
    }
  else show_error("Create and/or select a room to start");

}
void main_view::show_date_input() const {
  if(active_room) {
      date_picker_view* date_window = new date_picker_view();
      connect(date_window,SIGNAL(event_send_interval(QDateTime,QDateTime)),this,SLOT(action_fetch_by_date(QDateTime,QDateTime)));
      date_window->exec();
    }
  else show_error("Create and/or select a room to start");
}

// SLOTS - USER ACTIONS
void main_view::action_show_room_info() const{
  if(active_room){
      emit event_show_room_info(active_room);
      update_room_info();
    }
  else show_error("Create and/or select a room to start");
}
void main_view::action_sort_entries() const {
  if(active_room) entry_source->sort_items();
  else show_error("Create and/or select a room to start");
}
void main_view::action_leave_room(){
  if(active_room){
      QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Leave room", "Are you sure?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {

          emit event_leave_room(active_room);
          emit event_fetch_user_rooms();

          active_room = nullptr;
          load_entries(nullptr);
          disable_room_actions();
        }
    }
  else show_error("Create and/or select a room to start");
}
void main_view::action_forward_entry(){
  if(active_entry) {
      auto i = active_room->num_entries();
      emit event_forward_entry(*active_entry);
      if (active_room->num_entries() > i) emit event_fetch_room_entries(active_room);
    }
}
void main_view::action_delete_entry(){
  if(active_entry) {
      emit event_delete_entry(active_room,active_entry);
      active_entry = nullptr;
      emit event_fetch_room_entries(active_room);
      action_remove_entry_focus();
    }
  else show_error("Select an entry first");

}

void main_view::action_select_room(const QModelIndex &current) {
  auto sel = room_source->dataForIndex(current);
  if(sel != active_room) {
      active_room = sel;
      enable_room_actions();
      update_room_info();
      emit event_fetch_room_entries(active_room);
      if(entry_action_wdg->isVisible()) disable_entry_actions();
    }
}
void main_view::action_select_entry(const QModelIndex &current) {
  auto sel = entry_source->dataForIndex(current);
  if(sel != active_entry) {
      active_entry = sel;
      enable_entry_actions();

      if(active_entry->is_message()){
          forward_btn->show();
          if(active_entry->get_type() == entry_type::image_file)
            preview_btn->show();
          else
            preview_btn->hide();
        }
      else
        forward_btn->hide();
    }
}


void main_view::action_logout() const {
  emit event_logout();
}
void main_view::action_quit() const {
  emit event_quit();
}
void main_view::action_show_profile() const {
  emit event_show_user_profile();
}
void main_view::action_show_create_room() const {
  emit event_show_create_room();
  emit event_fetch_user_rooms();
}

void main_view::action_send_text() {
  if(active_room) {
      if(!text_ln->text().isEmpty()){
          emit event_send_text(active_room, text_ln->text(), active_entry);
          emit event_fetch_room_entries(active_room);
          action_remove_entry_focus();
          text_ln->clear();
        }
    }
  else show_error("Create and/or select a room to start");
}
void main_view::action_send_file(const QString& path) {
  emit event_send_file(active_room, path, active_entry);
  emit event_fetch_room_entries(active_room);
  action_remove_entry_focus();
}
void main_view::action_send_location(const QString& lat, const QString& lon) {
  emit event_send_location(active_room, lat, lon, active_entry);
  emit event_fetch_room_entries(active_room);
  action_remove_entry_focus();

}
void main_view::action_send_contact(const QString& name, const QString& contact) {
  emit event_send_contact(active_room, name, contact, active_entry);
  emit event_fetch_room_entries(active_room);
  action_remove_entry_focus();
}

void main_view::action_fetch_by_text() const {
  if(active_room) {
      bool ok;
      QString text = QInputDialog::getText(nullptr, tr("Filter by text"), tr("Search for entries that contain this text:"), QLineEdit::Normal, "", &ok);
      if(ok && !text.isEmpty()) emit event_fetch_by_text(active_room, text);
    }
  else show_error("Create and/or select a room to start");
}
void main_view::action_fetch_by_date(const QDateTime& start, const QDateTime& end) const {
  if(active_room) emit event_fetch_by_date(active_room, start, end);
  else show_error("Create and/or select a room to start");
}
void main_view::action_fetch_by_type_text() const {
  if(active_room) emit event_fetch_by_type(active_room, entry_type::text_message);
  else show_error("Create and/or select a room to start");
}
void main_view::action_fetch_by_type_contact() const {
  if(active_room) emit event_fetch_by_type(active_room, entry_type::contact_message);
  else show_error("Create and/or select a room to start");
}
void main_view::action_fetch_by_type_location() const{
  if(active_room) emit event_fetch_by_type(active_room, entry_type::location_message);
  else show_error("Create and/or select a room to start");
}
void main_view::action_fetch_by_type_file() const {
  if(active_room) emit event_fetch_by_type(active_room, entry_type::generic_file);
  else show_error("Create and/or select a room to start");

}
void main_view::action_fetch_by_type_image() const {
  if(active_room) emit event_fetch_by_type(active_room, entry_type::image_file);
  else show_error("Create and/or select a room to start");
}

void main_view::action_remove_entry_focus() {
  disable_entry_actions();
  active_entry = nullptr;
}
void main_view::action_image_view() const {
  if(active_entry){
      image_view* view_img_window = new image_view(QString::fromStdString(static_cast<image_file*>(active_entry)->get_path()));
      view_img_window->exec();
    }
}
void main_view::action_refresh_room() const{
  if(active_room) emit event_fetch_room_entries(active_room);
  else show_error("Create and/or select a room to start");
}
