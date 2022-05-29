#include "myliststandarditemmodel.h"

bool MyListStandardItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    QVariant res(value);
    if(role == Qt::EditRole) {
        MyItem temp = getItem(value.toString());
        item(index.row())->setIcon(temp.icon);
        res = temp.name;
    }
    return QStandardItemModel::setData(index, res, role);
}

void MyListStandardItemModel::initItems()
{
    map_names["c++"] = MyItem("C++", ":/icons/src/cpp.png");
    map_names["c#"] = MyItem("C#", ":/icons/src/c_sh.png");
    map_names["java"] = MyItem("Java", ":/icons/src/java.png");
    map_names["javascript"] = MyItem("JavaScript", ":/icons/src/js.png");
    map_names["python"] = MyItem("Python", ":/icons/src/py.png");
    map_names["php"] = MyItem("PHP", ":/icons/src/php.png");
    QMap<QString, MyItem>::iterator it;
    for(it=map_names.begin(); it!= map_names.end(); ++it)
        appendRow(it.value().name);
}

MyItem MyListStandardItemModel::getItem(QString key)
{
    QMap<QString, MyItem>::iterator it = map_names.find(key.toLower());
    if(it == map_names.end())
        return MyItem(key, QApplication::style()->standardIcon(QStyle::SP_MediaPlay));
    return map_names[key.toLower()];
}

MyMode MyListStandardItemModel::getItemMode(bool key)
{
    return map_mode[key];
}
void MyListStandardItemModel::initViewModes()
{
    map_mode[true] = MyMode("влево", "вправо", QListView::IconMode);
    map_mode[false] = MyMode("вверх", "вниз", QListView::ListMode);

}
bool MyListStandardItemModel::getSelectedIndex(QModelIndex * cur, QItemSelectionModel * sel_model)
{
    if (sel_model->hasSelection()) {
        *cur = sel_model->currentIndex();
        return cur->isValid();
    }
    return false;
}

void MyListStandardItemModel::removeRow(QListView *view)
{
    QItemSelectionModel * sel_model = view->selectionModel();
    QModelIndex cur;
    if(getSelectedIndex(&cur, sel_model))
        QStandardItemModel::removeRow(cur.row());
}

void MyListStandardItemModel::appendRow(QString txt)
{
    if (!txt.isEmpty()) {
        MyItem temp = getItem(txt);
        QStandardItemModel::appendRow(new QStandardItem(temp.icon, temp.name));
    }
}

void MyListStandardItemModel::moveRow(int count, QListView *view)
{
    QItemSelectionModel * sel_model = view->selectionModel();
    QModelIndex cur;
    if(getSelectedIndex(&cur, sel_model)) {
        int row_count = rowCount();
        int cur_row = cur.row();
        int new_row = cur_row + count;
        if(new_row >= 0 && new_row < row_count) {
            QList<QStandardItem *> ql = takeRow(cur_row);
            insertRow(new_row, ql);
            sel_model->setCurrentIndex(index(new_row, 0), QItemSelectionModel::ClearAndSelect);
        }
    }
}
