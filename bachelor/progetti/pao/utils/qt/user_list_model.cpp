#include "user_list_model.h"

user_list_model::user_list_model(const std::vector<user*>& users, QObject *parent) :
  QAbstractListModel(parent), _users(users) {}

int user_list_model::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)
  return _users.size();
}

QVariant user_list_model::data(const QModelIndex &index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (index.row() >= static_cast<int>(_users.size()))
    return QVariant();

  if (role == Qt::DisplayRole)
    return QString::fromStdString(_users.at(index.row())->get_username());
  else
    return QVariant();
}

const user* user_list_model::dataForIndex(const QModelIndex &index) const
{
  if (!index.isValid())
    return nullptr;
  return _users.at(index.row());
}

user* user_list_model::dataForIndex(const QModelIndex &index) {
  if (!index.isValid())
    return nullptr;
  return _users.at(index.row());
}
