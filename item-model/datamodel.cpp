#include "datamodel.h"

DataModel::DataModel(QObject *parent) : QAbstractItemModel(parent)
{

}

int DataModel::columnCount(const QModelIndex &) const
{
    return 1;
}

int DataModel::rowCount(const QModelIndex &) const
{
    return m_data.size();
}

QVariant DataModel::data(const QModelIndex &index, int role) const
{
    if( role == Qt::DisplayRole )
    {
        return m_data.at(index.row());
    }
    return QVariant();
}

QModelIndex DataModel::index(int row, int column, const QModelIndex &) const
{
    return createIndex(row, column, (void*)&m_data[row]);
}

QModelIndex DataModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}

void DataModel::addValue(const QString &value)
{
    m_data.append(value);
    emit layoutChanged();
}
