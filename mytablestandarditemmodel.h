#ifndef MYTABLESTANDARDITEMMODEL_H
#define MYTABLESTANDARDITEMMODEL_H

#include <QStandardItemModel>
#include <QTableView>

class MyTableStandardItemModel : public QStandardItemModel
{
public:
    void initHeader();
    void initItems();
    void paintBackground(QTableView * view);
    void clearBackground();
private:
    void addRow(QString n, QString comp, QString ip, QString mac, bool caption=false);
private:
    QVariant color;
};


#endif // MYTABLESTANDARDITEMMODEL_H
