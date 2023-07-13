#include "forward_view.h"

forward_view::forward_view(room_list_model* src, const entry& e) : room_source(src), _e(e) {
  setWindowTitle("Forward to...");
  setFixedSize(270,330);

  create_widgets();
  setup_gui_hierarchy();
  setup_properties();
  setup_connections();

  QMetaObject::connectSlotsByName(this);
}

forward_view::~forward_view(){
  delete info_lb;
  delete room_ls;
  delete cancel_btn;
  delete confirm_btn ;
  delete room_source;
}

// GUI

void forward_view::create_widgets(){
  info_lb = new QLabel();
  room_ls = new QListView();
  cancel_btn = new QPushButton();
  confirm_btn = new QPushButton();
}
void forward_view::setup_gui_hierarchy(){
  // layouts definition
  QVBoxLayout* main_vl = new QVBoxLayout();
  QHBoxLayout* btn_hl = new QHBoxLayout();

  // gui hierarchy definition
  this->setLayout(main_vl);
  main_vl->addWidget(info_lb);
  main_vl->addWidget(room_ls);
  main_vl->addLayout(btn_hl);
  btn_hl->addWidget(cancel_btn);
  btn_hl->addWidget(confirm_btn);
}
void forward_view::setup_properties() const {
  info_lb->setText(QString::fromStdString("Select a room to forward: \"" + _e.to_string()));
  info_lb->setAlignment(Qt::AlignCenter);
  info_lb->setWordWrap(true);
  cancel_btn->setText("Cancel");
  confirm_btn->setText("Forward");
  room_ls->setSelectionMode(QAbstractItemView::SingleSelection);
  room_ls->setModel(room_source);
}
void forward_view::setup_connections() const{
  connect(cancel_btn,SIGNAL(clicked()),this,SLOT(close()));
  connect(confirm_btn,SIGNAL(clicked()),this,SLOT(action_forward_to()));
}

// USER ACTIONS

void forward_view::action_forward_to(){
  auto i = room_ls->currentIndex();
  if(i.isValid()) {
      auto r = room_source->dataForIndex(i);
      emit event_forward_to(r, _e);
      close();
    }
}
