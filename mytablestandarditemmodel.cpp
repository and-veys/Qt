#include "mytablestandarditemmodel.h"

void MyTableStandardItemModel::addRow(QString n, QString comp, QString ip, QString mac, bool caption)
{
    QStringList row;
    row.append(n);
    row.append(comp);
    row.append(ip);
    row.append(mac);
    if(caption)
        setHorizontalHeaderLabels(row);
    else {
        QList<QStandardItem*> row_item;
        for(int i=0; i<row.count(); ++i)
            row_item.append(new QStandardItem(row[i]));
        appendRow(row_item);
    }
}
void MyTableStandardItemModel::initHeader()
{
    addRow("№", "Компьютер", "IP-адресс", "MAC-адресс", true);
}

void MyTableStandardItemModel::initItems()
{
    addRow("153", "PC0153", "10.10.0.2", "00:26:57:00:1f:02");
    addRow("244", "PC0244", "10.10.0.4", "00:26:52:01:1a:07");
    addRow("857", "PC0857", "10.10.0.10", "00:26:51:00:2b:04");
    addRow("432", "PC0432", "10.10.0.8", "00:26:48:00:7d:00");
    addRow("782", "PC0782", "10.10.0.7", "00:26:59:09:4c:01");
    color = data(indexFromItem(item(0,0)), Qt::BackgroundRole);
}

void MyTableStandardItemModel::paintBackground(QTableView * view)
{
    QItemSelectionModel * sel_model = view->selectionModel();
    QModelIndexList ind = sel_model->selectedIndexes();
    for(int i=0; i<ind.count(); ++i) {
        setData(ind[i], QColor(Qt::yellow), Qt::BackgroundRole);
        sel_model->setCurrentIndex(ind[i], QItemSelectionModel::Clear);
    }
}

void MyTableStandardItemModel::clearBackground()
{
    for(int i=0; i< rowCount(); ++i)
        for(int j=0; j<columnCount(); ++j)
            setData(indexFromItem(item(i,j)), color, Qt::BackgroundRole);
}
