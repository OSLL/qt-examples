#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QStringList>

class DataModel : public QAbstractItemModel
{
   Q_OBJECT

    QStringList m_data;

public:
    DataModel(QObject *parent);

    // Model interface implementation

    virtual int columnCount(const QModelIndex &parent) const;
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent) const;
    virtual QModelIndex parent(const QModelIndex &index) const;

public slots:
    void addValue(const QString &value);

};

#endif // DATAMODEL_H
