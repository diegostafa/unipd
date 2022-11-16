#include "create_room_view.h"

create_room_view::create_room_view(user_list_model* user_src) :
  user_source(user_src)
{
  setWindowTitle("Grammer - room Creation");
  setFixedSize(270,330);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

create_room_view::~create_room_view(){
  delete room_name_ln;
  delete members_ls;
  delete notice_lb;
  delete cancel_btn;
  delete confirm_btn;
  delete user_source;
}

// GUI

void create_room_view::create_widgets(){
  room_name_ln = new QLineEdit();
  members_ls = new QListView();
  notice_lb = new QLabel();
  cancel_btn = new QPushButton();
  confirm_btn = new QPushButton();
}
void create_room_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(room_name_ln);
  main_vl->addWidget(members_ls);
  main_vl->addWidget(notice_lb);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(confirm_btn);
}
void create_room_view::setup_properties() const {
  room_name_ln->setPlaceholderText("Room name...");
  notice_lb->setAlignment(Qt::AlignCenter);
  notice_lb->setWordWrap(true);
  cancel_btn->setText("Cancel");
  confirm_btn->setText("Create");
  members_ls->setSelectionMode(QAbstractItemView::MultiSelection);
  members_ls->setModel(user_source);
}
void create_room_view::setup_connections() const{
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(confirm_btn,SIGNAL(clicked()),this,SLOT(action_create_room()));
}

// USER ACTIONS

void create_room_view::action_create_room(){
  if(!room_name_ln->text().isEmpty()) {
      QStringList members;
      auto indexes = members_ls->selectionModel()->selectedIndexes();
      if(indexes.size() != 0) {
          for (auto i = indexes.cbegin() ; i != indexes.cend() ; ++i )
            members << i->data(Qt::DisplayRole).toString();
          emit event_create_room(room_name_ln->text(), members);
          close();
        }
      notice_lb->setText("No members selected");
    }
  else
    notice_lb->setText("Give a proper name");
}

