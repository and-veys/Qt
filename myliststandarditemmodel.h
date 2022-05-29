#ifndef MYLISTSTANDARDITEMMODEL_H
#define MYLISTSTANDARDITEMMODEL_H

#include <QApplication>
#include <QStandardItemModel>
#include <QListView>

class MyItem
{
public:
    MyItem(){};
    MyItem(QString nm, QString ic):name(nm), icon(QIcon(ic)){}
    MyItem(QString nm, QIcon ic):name(nm), icon(ic){}
public:
    QString name;
    QIcon icon;
};

class MyMode
{
public:
    MyMode(){}
    MyMode(QString but_1, QString but_2, QListView::ViewMode mod):
        text_button_1(but_1), text_button_2(but_2), view_mode(mod){}
public:
    QString text_button_1;
    QString text_button_2;
    QListView::ViewMode view_mode;

};

class MyListStandardItemModel : public QStandardItemModel
{
public:
        bool setData(const QModelIndex &index, const QVariant &value, int role) override;
        void initItems();
        void initViewModes();
        MyItem getItem(QString key);
        MyMode getItemMode(bool key);
        void moveRow(int count, QListView * view);
        void removeRow(QListView * view);
        void appendRow(QString txt);
private:
        QMap<QString, MyItem> map_names;
        QMap<bool, MyMode> map_mode;
private:
        bool getSelectedIndex(QModelIndex * cur, QItemSelectionModel * sel_model);
};

#endif // MYLISTSTANDARDITEMMODEL_H
