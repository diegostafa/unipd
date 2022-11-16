#include "room_list_model.h"

room_list_model::room_list_model(const std::vector<room*>& rooms, QObject *parent) :
  QAbstractListModel(parent), _rooms(rooms) {}

int room_list_model::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(&parent)
      return _rooms.size();
}

QVariant room_list_model::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (index.row() >= static_cast<int>(_rooms.size()))
    return QVariant();

  if (role == Qt::DisplayRole)
    return QString::fromStdString(_rooms.at(index.row())->get_name());
  else
    return QVariant();
}


const room* room_list_model::dataForIndex(const QModelIndex &index) const {
  if (!index.isValid())
    return nullptr;
  return _rooms.at(index.row());
}

room* room_list_model::dataForIndex(const QModelIndex &index) {
  if (!index.isValid())
    return nullptr;
  return _rooms.at(index.row());
}
