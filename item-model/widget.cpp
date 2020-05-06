#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_model = new DataModel(this);
    m_list = new QListView(this);
    m_list->setModel(m_model);

    m_edit = new QLineEdit("New value",this);
    m_btnAdd = new QPushButton("Add value", this);
    m_btnDel = new QPushButton("Delete value", this);


    setLayout(new QVBoxLayout);

    QHBoxLayout *lay = new QHBoxLayout;
    lay->addWidget(m_edit);
    lay->addWidget(m_btnAdd);
    lay->addWidget(m_btnDel);

    layout()->addWidget(m_list);
    layout()->addItem(lay);

    connect(m_btnAdd, SIGNAL(clicked(bool)),this,SLOT(insertValueFromLineEdit()));
}

Widget::~Widget()
{

}

void Widget::insertValueFromLineEdit()
{
   m_model->addValue(m_edit->text());
}
