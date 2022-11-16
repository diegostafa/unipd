#include "send_contact_view.h"

send_contact_view::send_contact_view() {
  setWindowTitle("Send Contact");
  setFixedSize(270,180);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

send_contact_view::~send_contact_view(){
  delete name_ln;
  delete number_ln;
  delete cancel_btn;
  delete send_btn;
}

void send_contact_view::create_widgets(){
  name_ln = new QLineEdit();
  number_ln = new QLineEdit();
  cancel_btn = new QPushButton();
  send_btn = new QPushButton();
}

void send_contact_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(name_ln);
  main_vl->addWidget(number_ln);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(send_btn);
}

void send_contact_view::setup_properties(){
  name_ln->setPlaceholderText("Name...");
  number_ln->setPlaceholderText("Contact number...");
  //number_ln->setValidator(new QIntValidator(0, 9));
  cancel_btn->setText("Cancel");
  send_btn->setText("Send");
}

void send_contact_view::setup_connections(){
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(send_btn,SIGNAL(clicked()),this,SLOT(action_send_contact()));
}

void send_contact_view::action_send_contact(){
  if(!name_ln->text().isEmpty() && !number_ln->text().isEmpty()){
      emit event_send_contact(name_ln->text(), number_ln->text());
      close();
    }
}

