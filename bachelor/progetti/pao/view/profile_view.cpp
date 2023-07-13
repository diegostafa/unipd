#include "profile_view.h"

profile_view::profile_view(const user& user) :
  u(user)
{
  setWindowTitle("Grammer - profile");
  setFixedSize(270,180);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

profile_view::~profile_view(){
  delete username_lb;
  delete pw_lb;
  delete pw_ln;
  delete pw_cb;
  delete notice_lb;
  delete cancel_btn;
  delete save_btn;
}

void profile_view::create_widgets(){
  username_lb = new QLabel();
  pw_lb = new QLabel();
  pw_ln = new QLineEdit();
  pw_cb = new QCheckBox();
  notice_lb = new QLabel();
  cancel_btn = new QPushButton();
  save_btn = new QPushButton();
}

void profile_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* pw_hl = new QHBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(username_lb);
  main_vl->addLayout(pw_hl);
  pw_hl->addWidget(pw_lb);
  pw_hl->addWidget(pw_ln);
  pw_hl->addWidget(pw_cb);
  main_vl->addWidget(notice_lb);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(save_btn);
}

void profile_view::setup_properties()const{
  username_lb->setText(QString::fromStdString(u.get_username()));
  username_lb->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
  username_lb->setAlignment(Qt::AlignCenter);
  pw_lb->setText("Password");
  pw_ln->setText(QString::fromStdString(u.get_password()));
  pw_ln->setEchoMode(QLineEdit::Password);
  pw_ln->setValidator(new QRegExpValidator(QRegExp(".{1,10}")));
  notice_lb->setAlignment(Qt::AlignCenter);
  notice_lb->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
  notice_lb->setWordWrap(true);
  cancel_btn->setText("Cancel");
  save_btn->setText("Save");
  notice_lb->hide();
}

void profile_view::setup_connections(){
  connect(pw_cb,SIGNAL(toggled(bool)),this,SLOT(action_toggle(bool)));
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(save_btn,SIGNAL(clicked()),this,SLOT(action_update_password()));
}

void profile_view::set_notice_error(const QString &err){
  notice_lb->show();
  notice_lb->setText(err);
}

void profile_view::action_toggle(bool checked)const{
  pw_ln->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password );
}

void profile_view::action_update_password(){
  auto p = pw_ln->text();
  if(u.get_password() == p.toStdString())
    close();

  if(p.length() >= 4){
      emit event_update_password(p);
      close();
    }
  else set_notice_error("Password too short");

}

