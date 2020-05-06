#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListView>

#include "datamodel.h"

class Widget : public QWidget
{
    Q_OBJECT

    QListView   *m_list;
    QLineEdit   *m_edit;
    QPushButton *m_btnAdd;
    QPushButton *m_btnDel;

    DataModel   *m_model;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void insertValueFromLineEdit();

};

#endif // WIDGET_H
