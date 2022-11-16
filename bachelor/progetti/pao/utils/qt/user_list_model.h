#ifndef USER_LIST_MODEL_H
#define USER_LIST_MODEL_H

#include "../../model/user.h"
#include <QAbstractListModel>


class user_list_model : public QAbstractListModel
{
  Q_OBJECT
private:
  std::vector<user*>  _users;

public:
  user_list_model(const std::vector<user*>& source, QObject *parent = nullptr);

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role) const override;

  const user* dataForIndex(const QModelIndex &index) const;

  user* dataForIndex(const QModelIndex &index);
};
#endif // USER_LIST_MODEL_H
