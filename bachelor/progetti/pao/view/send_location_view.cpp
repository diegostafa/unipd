#include "send_location_view.h"

send_location_view::send_location_view() {
  setWindowTitle("Send Location");
  setFixedSize(270,180);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

send_location_view::~send_location_view(){
  delete lat_lb;
  delete lon_lb;
  delete lat_sb;
  delete lon_sb;
  delete cancel_btn;
  delete send_btn;
}

void send_location_view::create_widgets(){
  lat_lb = new QLabel();
  lon_lb = new QLabel();
  lat_sb = new QDoubleSpinBox();
  lon_sb = new QDoubleSpinBox();
  cancel_btn = new QPushButton();
  send_btn = new QPushButton();
}

void send_location_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* lat_hl = new QHBoxLayout();
  QHBoxLayout* lon_hl = new QHBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addLayout(lat_hl);
  lat_hl->addWidget(lat_lb);
  lat_hl->addWidget(lat_sb);
  main_vl->addLayout(lon_hl);
  lon_hl->addWidget(lon_lb);
  lon_hl->addWidget(lon_sb);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(send_btn);
}

void send_location_view::setup_properties(){

  lat_lb->setText("Latitude (-90/+90)");
  lon_lb->setText("Longitude (-180/+180)");

  lat_lb->setAlignment(Qt::AlignCenter);
  lon_lb->setAlignment(Qt::AlignCenter);

  lat_sb->setDecimals(4);
  lat_sb->setMaximum(90);
  lat_sb->setMinimum(-90);
  lon_sb->setDecimals(4);
  lon_sb->setMaximum(180);
  lon_sb->setMinimum(-180);

  cancel_btn->setText("Cancel");
  send_btn->setText("Send");
}

void send_location_view::setup_connections(){
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(send_btn,SIGNAL(clicked()),this,SLOT(action_send_location()));
}

void send_location_view::action_send_location(){
  auto lat = lat_sb->cleanText();
  auto lon = lon_sb->cleanText();
  if(!lat.isEmpty() && !lon.isEmpty()){
      emit event_send_location(lat, lon);
      close();
    }
}

