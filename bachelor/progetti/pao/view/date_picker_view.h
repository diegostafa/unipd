#ifndef DATE_PICKER_VIEW_H
#define DATE_PICKER_VIEW_H

#include <QDialog>
#include <QDateTimeEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

class date_picker_view : public QDialog
{
  Q_OBJECT
private:
  QLabel* start_lb;
  QLabel* end_lb;
  QDateTimeEdit* start_dt;
  QDateTimeEdit* end_dt;
  QPushButton* cancel_btn;
  QPushButton* send_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties();
  void setup_connections();

private slots:
  void action_send_interval();
public:
  date_picker_view();
  ~date_picker_view();
signals:
  void event_send_interval(const QDateTime& start, const QDateTime& end);
};
#endif // DATE_PICKER_VIEW_H
