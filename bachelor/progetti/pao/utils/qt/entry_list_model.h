#ifndef ENTRY_LIST_MODEL_H
#define ENTRY_LIST_MODEL_H

#include "../../model/room.h"
#include <algorithm>
#include <QAbstractListModel>

class entry_list_model : public QAbstractListModel
{
  Q_OBJECT
private:
  std::vector<entry*>  _entries;

public:
  entry_list_model(const std::vector<entry*>& source, QObject *parent = nullptr);
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  const entry* dataForIndex(const QModelIndex &index) const;
  entry* dataForIndex(const QModelIndex &index);
  void sort_items();
};
#endif // ENTRY_LIST_MODEL_H
