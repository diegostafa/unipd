#ifndef CREATE_ROOM_VIEW_H
#define CREATE_ROOM_VIEW_H

#include "../utils/qt/user_list_model.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>

class create_room_view : public QDialog
{
  Q_OBJECT
private:
  user_list_model* user_source;

  QLineEdit* room_name_ln;
  QListView* members_ls;
  QLabel* notice_lb;
  QPushButton* cancel_btn;
  QPushButton* confirm_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties() const;
  void setup_connections() const;

public:
  create_room_view(user_list_model* users);
  ~create_room_view();

private slots:
  void action_create_room();

signals:
  void event_create_room(const QString& name, const QStringList& members);
};

#endif // CREATE_ROOM_VIEW_H
