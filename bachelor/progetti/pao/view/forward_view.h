#ifndef FORWARD_VIEW_H
#define FORWARD_VIEW_H

#include "../utils/qt/room_list_model.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>

class forward_view : public QDialog
{
  Q_OBJECT
private:
  room_list_model* room_source;
  const entry& _e;

  QLabel* info_lb;
  QListView* room_ls;
  QPushButton* cancel_btn;
  QPushButton* confirm_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties() const;
  void setup_connections() const;

public:
  forward_view(room_list_model* src, const entry& e);
  ~forward_view();

private slots:
  void action_forward_to();

signals:
  void event_forward_to(room* r, const entry& e);
};
#endif // FORWARD_VIEW_H
