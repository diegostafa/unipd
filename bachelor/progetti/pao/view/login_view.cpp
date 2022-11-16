#include "login_view.h"

login_view::login_view() {

  setWindowTitle("Grammer - login");
  setFixedSize(400, 300);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

login_view::~login_view() {
  delete title_lb;
  delete username_lb;
  delete password_lb;
  delete notice_lb;
  delete username_ln;
  delete password_ln;
  delete close_btn;
  delete register_btn;
  delete login_btn;
}

void login_view::create_widgets(){
  title_lb = new QLabel();
  username_lb = new QLabel();
  password_lb = new QLabel();
  notice_lb = new QLabel();
  username_ln = new QLineEdit();
  password_ln = new QLineEdit();
  close_btn = new QPushButton();
  register_btn = new QPushButton();
  login_btn = new QPushButton();
}

void login_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* username_hl = new QHBoxLayout();
  QHBoxLayout* password_hl = new QHBoxLayout();
  QHBoxLayout* action_hl = new QHBoxLayout();
  QSpacerItem* spc_v = new QSpacerItem(1,1, QSizePolicy::Fixed, QSizePolicy::Expanding);

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addSpacerItem(spc_v);
  main_vl->addWidget(title_lb);
  main_vl->addSpacerItem(spc_v);
  main_vl->addLayout(username_hl);
  username_hl->addWidget(username_lb);
  username_hl->addWidget(username_ln);
  main_vl->addLayout(password_hl);
  password_hl->addWidget(password_lb);
  password_hl->addWidget(password_ln);
  main_vl->addSpacerItem(spc_v);
  main_vl->addWidget(notice_lb);
  main_vl->addSpacerItem(spc_v);
  main_vl->addLayout(action_hl);
  action_hl->addWidget(close_btn);
  action_hl->addWidget(register_btn);
  action_hl->addWidget(login_btn);
}

void login_view::setup_properties()const{
  title_lb->setText("Grammer");
  title_lb->setAlignment(Qt::AlignCenter);
  title_lb->setFont(QFont("Liberation sans", 11, QFont::Bold));
  username_lb->setText("Username");
  username_lb->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
  username_lb->setAlignment(Qt::AlignCenter);
  password_lb->setText("Password");
  password_lb->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
  password_lb->setAlignment(Qt::AlignCenter);
  notice_lb->setText("Register a new username, or login into your account");
  notice_lb->setAlignment(Qt::AlignCenter);
  notice_lb->setWordWrap(true);
  username_ln->setPlaceholderText("Username");
  username_ln->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9]{1,10}")));
  password_ln->setPlaceholderText("Password");
  password_ln->setEchoMode(QLineEdit::Password);
  password_ln->setValidator(new QRegExpValidator(QRegExp(".{1,10}")));
  close_btn->setText("Quit");
  login_btn->setText("Log In");
  register_btn->setText("Register");
}

void login_view::setup_connections()const{
  connect(close_btn,SIGNAL(clicked()),this,SLOT(action_close_login()));
  connect(login_btn,SIGNAL(clicked()),this,SLOT(action_login_user()));
  connect(register_btn,SIGNAL(clicked()),this,SLOT(action_register_user()));
}

void login_view::closeEvent(QCloseEvent *event) {
  if (event->spontaneous()) emit event_close_login();
  else QWidget::closeEvent(event);
}

void login_view::clear_input() const{
  username_ln->clear();
  password_ln->clear();
}

void login_view::set_input_error() const{
  clear_input();
  notice_lb->setText("The username and password must contain at least 4 characters");
}

void login_view::set_error(const QString& s) const{
  clear_input();
  notice_lb->setText(s);
}


void login_view::action_login_user() const {
  if(username_ln->text().length() < 4 || password_ln->text().length() < 4)
    set_input_error();
  else
    emit event_login_user(username_ln->text(), password_ln->text());
}

void login_view::action_register_user() const{
  if(username_ln->text().length() < 4 || password_ln->text().length() < 4)
    set_input_error();
  else
    emit event_register_user(username_ln->text(), password_ln->text());
}


void login_view::action_close_login() const { emit event_close_login(); }
