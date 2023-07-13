#ifndef ROOM_LIST_MODEL_H
#define ROOM_LIST_MODEL_H

#include "../../model/room.h"
#include <QAbstractListModel>


class room_list_model : public QAbstractListModel
{
  Q_OBJECT
private:
  std::vector<room*>  _rooms;

public:
  room_list_model(const std::vector<room*>& source, QObject *parent = nullptr);

  int rowCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index, int role) const override;

  const room* dataForIndex(const QModelIndex &index) const;

  room* dataForIndex(const QModelIndex &index);
};
#endif // ROOM_LIST_MODEL_H
