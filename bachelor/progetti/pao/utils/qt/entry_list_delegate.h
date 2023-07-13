#ifndef ENTRY_LIST_DELEGATE_H
#define ENTRY_LIST_DELEGATE_H

#include "entry_list_model.h"
#include "../../model/hierarchy/entry_type.h"
#include "../../model/hierarchy/entry.h"

#include <QAbstractTextDocumentLayout>
#include <QPainterPath>
#include <QTextDocument>
#include <QAbstractItemDelegate>
#include <QPainter>
#include <QDateTime>
#include <QFontMetrics>
#include <sstream>

class entry_list_delegate : public QAbstractItemDelegate
{
private:
  void paint_message(QPainter * painter, const QStyleOptionViewItem & option, const message_entry* m) const;
public:
  entry_list_delegate(QObject *parent = nullptr);
  void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
  QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const;

};

#endif // ENTRY_LIST_DELEGATE_H
