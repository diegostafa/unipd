#ifndef SEND_LOCATION_VIEW_H
#define SEND_LOCATION_VIEW_H

#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QDoubleSpinBox>

class send_location_view : public QDialog
{
  Q_OBJECT
private:
  QLabel* lat_lb;
  QLabel* lon_lb;
  QDoubleSpinBox* lat_sb;
  QDoubleSpinBox* lon_sb;
  QPushButton* cancel_btn;
  QPushButton* send_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties();
  void setup_connections();

private slots:
  void action_send_location();
public:
  send_location_view();
  ~send_location_view();

signals:
  void event_send_location(const QString& lat, const QString& lon);
};

#endif // SEND_LOCATION_VIEW_H
