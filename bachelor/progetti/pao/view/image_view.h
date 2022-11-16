#ifndef IMAGE_VIEW_H
#define IMAGE_VIEW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>


class image_view : public QDialog
{
  Q_OBJECT
private:
  QLabel* img_lb;
  QPixmap p;
  QPushButton* close_btn;

  void create_widgets();
  void setup_gui_hierarchy();
  void setup_properties();
  void setup_connections();

public:
  image_view(const QPixmap& pm);
  ~image_view();
};
#endif // IMAGE_VIEW_H
