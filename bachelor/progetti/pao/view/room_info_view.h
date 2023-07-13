#ifndef ROOM_INFO_VIEW_H
#define ROOM_INFO_VIEW_H

#include "../model/room.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListView>
#include <QStringListModel>

class room_info_view : public QDialog
{
  Q_OBJECT
private:
  room* r;

  QLabel* name_lb;
  QLineEdit* name_ln;
  QListView* members_ls;
  QLabel* notice_lb;
  QPushButton* cancel_btn;
  QPushButton* save_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties() const;
  void setup_connections();
  void setup_models() const;
  void set_notice_error(const QString& s) const;

private slots:
  void action_save();

public:
  room_info_view(room* room);
  ~room_info_view();

signals:
  void event_update_room_name(room* r, const QString& name);
};


#endif // ROOM_INFO_VIEW_H
