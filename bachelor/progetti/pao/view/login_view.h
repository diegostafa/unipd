#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QPushButton>
#include <QVBoxLayout>
#include <QCloseEvent>

class login_view : public QWidget
{
  Q_OBJECT

private:
  QLabel* title_lb;
  QLabel* username_lb;
  QLabel* password_lb;
  QLabel* notice_lb;
  QLineEdit* username_ln;
  QLineEdit* password_ln;
  QPushButton* close_btn;
  QPushButton* register_btn;
  QPushButton* login_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties() const;
  void setup_connections() const;

public:
  login_view();
  ~login_view();

  void clear_input() const;
  void set_input_error() const;
  void set_error(const QString& s) const;

public slots:
  void action_close_login() const;
  void action_login_user() const;
  void action_register_user() const;

protected slots:
  void closeEvent(QCloseEvent *event) override;

signals:
  void event_close_login() const;
  void event_login_user(const QString& username, const QString& password) const;
  void event_register_user(const QString& username, const QString& password) const;

};

#endif // LOGIN_VIEW_H
