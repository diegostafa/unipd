#include "image_view.h"

image_view::image_view(const QPixmap& pm) : p(pm) {
  setWindowTitle("Image viewer");
  setFixedSize(400,400);
  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

image_view::~image_view(){
  delete img_lb;
  delete close_btn;
}

void image_view::create_widgets(){
  img_lb = new QLabel();
  close_btn = new QPushButton();
}

void image_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(img_lb);
  main_vl->addWidget(close_btn);
}

void image_view::setup_properties(){
  img_lb->setPixmap(p);
  img_lb->setScaledContents(true);
  img_lb->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

  close_btn->setText("Close");
}

void image_view::setup_connections(){
  connect(close_btn,SIGNAL(clicked()),this,SLOT(close()));
}
