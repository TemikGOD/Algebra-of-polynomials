#ifndef TABLEWINDOW_H
#define TABLEWINDOW_H

#include <QDialog>
#include "../Tables/TableInterface.hpp"
#include "QStandardItemModel"
#include "QStandardItem"

namespace Ui {
class TableWindow;
}

class TableWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TableWindow(QWidget *parent = nullptr, vector<TableInterface*>* tables = nullptr);
    ~TableWindow();

    unsigned int getCurTab();
    void setCurTab(unsigned int);

private slots:
    void on_pushAddButton_clicked();

private:
    Ui::TableWindow *ui;
    vector<TableInterface*>* tables;
    unsigned int currentTable;
    QStandardItemModel *model;
    QStandardItem *item;
};

#endif // TABLEWINDOW_H
