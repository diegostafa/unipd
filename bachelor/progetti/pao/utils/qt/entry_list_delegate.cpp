#include "entry_list_delegate.h"

entry_list_delegate::entry_list_delegate(QObject* parent) : QAbstractItemDelegate(parent) {}

void entry_list_delegate::paint_message(QPainter * painter, const QStyleOptionViewItem & option, const message_entry * m) const {
  /*
    MESSAGE BOX

    <username> in reply to <mes_id>   --> <header>
    <icon>   <content>                --> <body>
    <date>   <optional modified>      --> <footer>
  */

  // get attributes
  auto id = m->get_id();
  auto sender = m->get_sender();
  auto reply = m->get_reply();
  auto sent_t = m->get_time();
  auto type = m->get_type();
  auto modified = m->is_modified();
  auto forwarded = m->is_forwarded();
  QDateTime q_sent_t;
  q_sent_t.setTime_t(sent_t);

  // get icons
  QPixmap p;
  QIcon icon;
  int icon_space = 42;
  switch (type) {
    case entry_type::text_message:
      icon_space = 10;
      break;
    case entry_type::contact_message:
      p = QPixmap(":/contact.png");
      break;
    case entry_type::location_message:
      p = QPixmap(":/location.png");
      break;
    case entry_type::image_file:
      p = QPixmap(":/image.png");
      break;
    case entry_type::generic_file:
      p = QPixmap(":/file.png");
      break;
    }
  if(!p.isNull())
    icon = QIcon(p.scaled( QSize(24, 24), Qt::KeepAspectRatio, Qt::SmoothTransformation ));

  // message blocks
  auto header = sender + (reply ?  " in reply to #" + std::to_string(reply) : "");
  auto raw_content = m->to_string();
  auto footer ="ID: #" + std::to_string(id) + " - " + q_sent_t.time().toString().toStdString() + (modified ? " - modified" : "") + (forwarded ? " - forwarded" : "");

  // cap line lenght
  unsigned int max_line_lenght = 55;
  for(unsigned int i = 1; i < raw_content.size() - 1; i++)
      if(i % max_line_lenght == 0)
          raw_content.insert(i-1, 1, '\n');

  // split content by newlines
  std::vector<std::string> content;
  std::stringstream ss(raw_content);
  for (std::string line; std::getline(ss, line, '\n');)
    content.push_back(line);

  // fonts
  QFont header_font = QFont("Liberation mono", 10, QFont::Normal);
  QFont body_font = QFont("Liberation Sans", 10, QFont::Normal);
  QFont footer_font = QFont("Liberation mono", 8, QFont::Normal);
  footer_font.setItalic(true);
  QFontMetrics fmh(header_font);
  QFontMetrics fmb(body_font);
  QFontMetrics fmf(footer_font);

  // blocks size
  int header_pixels_w = fmh.width(QString::fromStdString(header));
  int body_pixels_w = fmb.width(QString::fromStdString(content[0]));
  int footer_pixels_w = fmf.width(QString::fromStdString(footer));
  int header_pixels_h = fmh.height();
  int body_pixels_h = fmb.height();
  int footer_pixels_h = fmf.height();
  auto h = body_pixels_h*content.size() > 24 ? body_pixels_h*content.size() : 24 ;

  //int bubble_size_h = body_pixels_h + footer_pixels_h + header_pixels_h;
  int bubble_size_w = std::max({header_pixels_w, footer_pixels_w, body_pixels_w });

  // paint message box
  QRect r = option.rect;

  if (option.state & QStyle::State_Selected)
    {
      painter->setPen(QColor::fromRgb(75,0,0));
      painter->setBrush(QColor::fromRgb(75,0,0));
      painter->drawRoundedRect(r.left() + 5, r.top() + 5, bubble_size_w + icon_space,20 + header_pixels_h + footer_pixels_h +  h, 10, 10);
    }
  else {
      painter->setPen(QColor::fromRgb(0, 0, 0));
      painter->setBrush(QColor::fromRgb(0, 0, 0));
      painter->drawRoundedRect(r.left() + 5, r.top() + 5, bubble_size_w + icon_space,20 + header_pixels_h + footer_pixels_h +  h, 10, 10);
    }

  // paint header
  r = option.rect.adjusted(10, 10, 0, 0);
  painter->setPen(Qt::green);
  painter->setFont(header_font);
  painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignTop|Qt::AlignLeft, QString::fromStdString(header), &r);

  // paint icon
  if(!icon.isNull()) {
      r = option.rect.adjusted(10, 15 + header_pixels_h, 0, 0);
      icon.paint(painter, r, Qt::AlignLeft);
    }

  // paint content
  painter->setPen(Qt::white);
  painter->setFont(body_font);
  for(unsigned int i = 1; i <= content.size(); i++){
      r = option.rect.adjusted(icon_space, 10 + header_pixels_h + body_pixels_h*i, 0, 0);
      painter->drawText(r.left(), r.top(), QString::fromStdString(content[i-1]));
    }

  // paint footer
  r = option.rect.adjusted(10, 20 +  footer_pixels_h + h, 0, 0);
  painter->setPen(Qt::lightGray);
  painter->setFont(footer_font);
  painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft, QString::fromStdString(footer), &r);
}

void entry_list_delegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
  painter->setRenderHint(QPainter::Antialiasing);

  auto e = static_cast<const entry_list_model*>(index.model())->dataForIndex(index);

  if(e->is_message())
    paint_message(painter, option, static_cast<const message_entry* >(e));

  sizeHint(option, index);
}

// set the height for the QListView item
QSize entry_list_delegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const {
  Q_UNUSED(index)
  Q_UNUSED(option)
  return QSize(120, 120);
/*
  if(index.row() == 0 || index.row() == pListWidget->count() -1)
     return customSize;
  else
     return QItemDelegate::sizeHint(..);
*/
}
