#include "entry_list_model.h"

entry_list_model::entry_list_model(const std::vector<entry*>& source, QObject *parent) :
  QAbstractListModel(parent), _entries(source) {}

int entry_list_model::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(&parent)
  return _entries.size();
}

QVariant entry_list_model::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();
  if (index.row() >= static_cast<int>(_entries.size()))
    return QVariant();
  if (role == Qt::DisplayRole)
    return QString::fromStdString(_entries.at(index.row())->to_string());
  else
    return QVariant();
}

const entry* entry_list_model::dataForIndex(const QModelIndex &index) const {
  if (!index.isValid())
    return nullptr;
  return _entries.at(index.row());
}

entry* entry_list_model::dataForIndex(const QModelIndex &index) {
  if (!index.isValid())
    return nullptr;
  return _entries.at(index.row());
}

void entry_list_model::sort_items(){
  std::sort(_entries.begin(), _entries.end(), [](entry* a, entry* b) { return a < b;});
}
