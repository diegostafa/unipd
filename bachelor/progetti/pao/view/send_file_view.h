#ifndef SEND_FILE_VIEW_H
#define SEND_FILE_VIEW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>


class send_file_view: public QDialog
{
  Q_OBJECT
private:
  const QString& path;
  QLabel* path_lb;
  QPushButton* cancel_btn;
  QPushButton* send_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties();
  void setup_connections();

private slots:
  void action_send_file();
public:
  send_file_view(const QString& p);
  ~send_file_view();

signals:
  void event_send_file(const QString& path);
};

#endif // SEND_FILE_VIEW_H
