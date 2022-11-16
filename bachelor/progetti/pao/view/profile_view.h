#ifndef PROFILE_VIEW_H
#define PROFILE_VIEW_H

#include "../model/user.h"

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QRegExpValidator>

class profile_view : public QDialog
{
  Q_OBJECT
private:
  const user& u;

  QLabel* username_lb;
  QLabel* pw_lb;
  QLineEdit* pw_ln;
  QCheckBox* pw_cb;
  QLabel* notice_lb;
  QPushButton* cancel_btn;
  QPushButton* save_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties()const;
  void setup_connections();
  void set_notice_error(const QString& err);

private slots:
  void action_update_password();
  void action_toggle(bool checked)const;
public:
  profile_view(const user& user);
  ~profile_view();

signals:
  void event_update_password(const QString& pw);
};

#endif // PROFILE_VIEW_H
