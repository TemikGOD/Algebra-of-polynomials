#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <tablewindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    unsigned int choosedTable;

private slots:
    void on_pushCalculateButton_clicked();

    void on_pushOpenTableButton_clicked();

private:
    Ui::MainWindow *ui;
    TableWindow *tabWin;
    vector<TableInterface*>* tables;
};
#endif // MAINWINDOW_H
