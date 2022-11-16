#include "date_picker_view.h"

date_picker_view::date_picker_view() {
  setWindowTitle("Date filter");
  setFixedSize(400,180);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

date_picker_view::~date_picker_view(){
  delete start_lb;
  delete end_lb;
  delete start_dt;
  delete end_dt;
  delete cancel_btn;
  delete send_btn;
}

void date_picker_view::create_widgets(){
  start_lb = new QLabel();
  end_lb = new QLabel();
  start_dt = new QDateTimeEdit();
  end_dt = new QDateTimeEdit();
  cancel_btn = new QPushButton();
  send_btn = new QPushButton();
}

void date_picker_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* start_hl = new QHBoxLayout();
  QHBoxLayout* end_hl = new QHBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addLayout(start_hl);
  start_hl->addWidget(start_lb);
  start_hl->addWidget(start_dt);
  main_vl->addLayout(end_hl);
  end_hl->addWidget(end_lb);
  end_hl->addWidget(end_dt);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(send_btn);
}

void date_picker_view::setup_properties(){
  start_lb->setText("Start date");
  start_lb->setAlignment(Qt::AlignCenter);
  end_lb->setText("End date");
  end_lb->setAlignment(Qt::AlignCenter);
  start_dt->setDate(QDate::currentDate());
  end_dt->setDate(QDate::currentDate());
  cancel_btn->setText("Cancel");
  send_btn->setText("Ok");
}

void date_picker_view::setup_connections(){
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(send_btn,SIGNAL(clicked()),this,SLOT(action_send_interval()));
}

void date_picker_view::action_send_interval(){
  emit event_send_interval(start_dt->dateTime(), end_dt->dateTime());
  close();
}

