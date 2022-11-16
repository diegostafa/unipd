#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "../view/login_view.h"
#include "../view/main_view.h"
#include "../view/create_room_view.h"
#include "../view/profile_view.h"
#include "../view/send_contact_view.h"
#include "../view/send_location_view.h"
#include "../view/send_file_view.h"
#include "../view/forward_view.h"
#include "../view/room_info_view.h"
#include "../model/user_db.h"
#include "../model/room_db.h"

#include <QFileDialog>
#include <QFile>
#include <vector>


class main_controller : public QObject
{
  Q_OBJECT
private:

  // MODEL
  user_db* users;
  room_db* rooms;
  user* active_user;

  // VIEWS
  login_view* login_window;
  main_view* main_window;

public:
  main_controller(QObject* parent = nullptr);
  ~main_controller();
  void exec();

private slots:

  // SHOW VIEWS
  void show_login();
  void close_login();
  void show_main();
  void close_main();
  void show_forward_entry(const entry& e) const;
  void show_user_profile() const;
  void show_create_room() const;
  void show_room_info(room* r) const;

  // UPDATE MAIN VIEW CONTENT
  void fetch_by_date(room* r, const QDateTime& start, const QDateTime& end) const;
  void fetch_by_type(room* r, entry_type t) const;
  void fetch_by_text(room* r, const QString& text) const;
  void fetch_user_rooms() const;
  void fetch_room_entries(room* r) const;

  // LOGIN VIEW ACTIONS
  void login_user(const QString & username, const QString & password);
  void register_user(const QString & username, const QString & password);

  // ROOMS ACTIONS
  void create_room(const QString & name, const QStringList& members) const;
  void update_password(const QString& pw) const;
  void update_room_name(room* r,const QString& s) const;
  void leave_room(room* r) const;

  // ENTRIES ACTIONS
  void send_text(room* r, const QString& content, entry* reply) const;
  void send_location(room* r, const QString& lat, const QString& lon, entry* reply) const;
  void send_contact(room* r, const QString& name,const QString& number, entry* reply) const;
  void send_file(room* r, const QString& path, entry* reply) const;
  void forward_entry(room* r, const entry& e) const;
  void delete_entry(room* r, entry* e) const;
};

#endif // MAIN_CONTROLLER_H
