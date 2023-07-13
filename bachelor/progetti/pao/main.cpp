#include <QtWidgets/QApplication>
#include "controller/main_controller.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  main_controller mc;
  mc.exec();
  return a.exec();
}
