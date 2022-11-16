#ifndef SEND_CONTACT_VIEW_H
#define SEND_CONTACT_VIEW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QIntValidator>

class send_contact_view : public QDialog
{
  Q_OBJECT
private:
  QLineEdit* name_ln;
  QLineEdit* number_ln;
  QPushButton* cancel_btn;
  QPushButton* send_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties();
  void setup_connections();

private slots:
  void action_send_contact();
public:
  send_contact_view();
  ~send_contact_view();

signals:
  void event_send_contact(const QString& name, const QString& number);
};
#endif // SEND_CONTACT_VIEW_H
