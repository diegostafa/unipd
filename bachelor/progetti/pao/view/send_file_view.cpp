#include "send_file_view.h"

send_file_view::send_file_view(const QString& p) : path(p) {
  setWindowTitle("Send File");
  setFixedSize(270,180);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

send_file_view::~send_file_view(){
  delete path_lb;
  delete cancel_btn;
  delete send_btn;
}

void send_file_view::create_widgets(){
  path_lb = new QLabel();
  cancel_btn = new QPushButton();
  send_btn = new QPushButton();
}

void send_file_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(path_lb);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(send_btn);
}

void send_file_view::setup_properties(){
  path_lb->setText("Do you want to send: " + path + " ?");
  path_lb->setWordWrap(true);
  path_lb->setAlignment(Qt::AlignCenter);
  cancel_btn->setText("Cancel");
  send_btn->setText("Send");
}

void send_file_view::setup_connections(){
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(send_btn,SIGNAL(clicked()),this,SLOT(action_send_file()));
}

void send_file_view::action_send_file(){
  emit event_send_file(path);
  close();
}

