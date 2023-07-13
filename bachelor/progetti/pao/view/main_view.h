#ifndef MAIN_VIEW_H
#define MAIN_VIEW_H


#include "../utils/qt/user_list_model.h"
#include "../utils/qt/room_list_model.h"
#include "../utils/qt/entry_list_model.h"
#include "../utils/qt/entry_list_delegate.h"

#include "send_file_view.h"
#include "send_contact_view.h"
#include "send_location_view.h"
#include "date_picker_view.h"
#include "image_view.h"

#include <QInputDialog>
#include <QSortFilterProxyModel>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QStringListModel>
#include <QTextEdit>
#include <QMenu>
#include <QAction>
#include <QCheckBox>
#include <QFileDialog>
#include <QCloseEvent>

class main_view : public QWidget {
  Q_OBJECT
private:

  // context
  const user* active_user;
  room* active_room;
  entry* active_entry;

  // list models
  room_list_model* room_source;
  entry_list_model* entry_source;
  QSortFilterProxyModel *proxy_room;

  // paint delegate
  entry_list_delegate* entry_delegate;

  // gui
  QPushButton* create_room_btn;
  QLineEdit *search_room_ln;
  QListView *rooms_ls;
  QToolButton *user_profile_tbtn;
  QWidget* room_action_wdg;
  QPushButton *active_room_btn;
  QToolButton *action_room_tbtn;
  QListView *entries_ls;
  QLabel* in_reply_to_lb;
  QPushButton *send_btn;
  QLineEdit *text_ln;
  QToolButton *more_entries_tbtn;
  QWidget* entry_action_wdg;
  QLabel* active_entry_lb;
  QPushButton* preview_btn;
  QPushButton* forward_btn;
  QPushButton* delete_btn;
  QPushButton* cancel_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties() const;
  void setup_styles() const;
  void setup_menus() const;
  void setup_connections() const;

  void update_room_info() const;
  void enable_room_actions() const;
  void disable_room_actions() const;
  void enable_entry_actions() const;
  void disable_entry_actions() const;

public:
  main_view(const user* logged_user);
  ~main_view();

  void show_error(const QString& err) const;

private slots:
  void action_leave_room();
  void action_remove_entry_focus();
  void action_select_room(const QModelIndex &current);
  void action_select_entry(const QModelIndex &current);
  void action_logout() const;
  void action_quit() const;
  void action_show_create_room() const;
  void action_show_profile() const;
  void action_show_room_info() const;
  void action_sort_entries() const;
  void action_send_text();
  void action_send_file(const QString& path);
  void action_send_location(const QString& lat, const QString& lon);
  void action_send_contact(const QString& name, const QString& contact);
  void action_forward_entry();
  void action_delete_entry();
  void action_fetch_by_date(const QDateTime& start, const QDateTime& end) const;
  void action_fetch_by_text() const;
  void action_fetch_by_type_text() const;
  void action_fetch_by_type_contact() const;
  void action_fetch_by_type_location() const;
  void action_fetch_by_type_file() const;
  void action_fetch_by_type_image() const;
  void show_date_input() const;
  void show_send_file() const;
  void show_send_location() const;
  void show_send_contact() const;
  void action_image_view() const;
  void action_refresh_room() const;

protected slots:
  void closeEvent(QCloseEvent *event) override;

public:
  void load_rooms(room_list_model* src);
  void load_entries(entry_list_model* src);

signals:
  void event_fetch_user_rooms() const;
  void event_fetch_room_entries(room* r) const;
  void event_fetch_by_date(room* r, const QDateTime& start, const QDateTime& end) const;
  void event_fetch_by_text(room* r, const QString& s) const;
  void event_fetch_by_type(room* r, entry_type t) const;
  void event_leave_room(room* r) const;
  void event_show_create_room() const;
  void event_show_user_profile() const;
  void event_show_room_info(room* r) const;
  void event_logout() const;
  void event_quit() const;
  void event_delete_entry(room* r, entry* e) const;
  void event_send_text(room* r, const QString& content, entry* reply) const;
  void event_send_file(room* r, const QString& path, entry* reply) const;
  void event_send_location(room* r, const QString& lat, const QString& lon, entry* reply) const;
  void event_send_contact(room* r, const QString& name,const QString& number, entry* reply) const;
  void event_forward_entry(const entry& e);

};
#endif // MAIN_VIEW_H
