#include "room_info_view.h"

room_info_view::room_info_view(room* room) : r(room){
  setWindowTitle("Grammer Room Info");
  setFixedSize(270,330);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_models();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

room_info_view::~room_info_view(){
  delete name_lb;
  delete name_ln;
  delete members_ls;
  delete notice_lb;
  delete cancel_btn;
  delete save_btn;
}

void room_info_view::create_widgets(){
  name_lb = new QLabel();
  name_ln = new QLineEdit();
  members_ls = new QListView();
  notice_lb = new QLabel();
  cancel_btn = new QPushButton();
  save_btn = new QPushButton();
}

void room_info_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* name_hl = new QHBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addLayout(name_hl);
  name_hl->addWidget(name_lb);
  name_hl->addWidget(name_ln);
  main_vl->addWidget(members_ls);
  main_vl->addWidget(notice_lb);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(save_btn);
}

void room_info_view::setup_properties() const {
  name_lb->setText("Room name");
  name_ln->setText(QString::fromStdString(r->get_name()));
  name_lb->setAlignment(Qt::AlignCenter);
  cancel_btn->setText("Close");
  save_btn->setText("Save");
  notice_lb->hide();
  members_ls->setSelectionMode(QAbstractItemView::NoSelection);
  members_ls->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void room_info_view::setup_models() const {
  auto src = r->get_all_members();
  QStringList sl;
  for(auto i = src.cbegin(); i!= src.cend(); i++)
    sl << QString::fromStdString(*i);
  members_ls->setModel(new QStringListModel(sl));
}

void room_info_view::setup_connections(){
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(save_btn,SIGNAL(clicked()),this,SLOT(action_save()));
}

void room_info_view::set_notice_error(const QString &err) const{
  notice_lb->show();
  notice_lb->setText(err);
}

void room_info_view::action_save(){
  auto p = name_ln->text();
  if(!p.isEmpty()){
      emit event_update_room_name(r,p);
      close();
    }
  else  set_notice_error("Password too short");

}

