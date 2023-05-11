#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "../Tables/OrderedArray.hpp"
#include "../Tables/AVLTreeTable.h"
#include "../Tables/ChainMethod.hpp"
#include "../Tables/LinearTableOnAnArray.h"
#include "../Tables/linearListTable.hpp"
#include "../Tables/OpenHashTable.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tables = new vector<TableInterface*>;
    LinearTableOnAnArray* linArrTab = new LinearTableOnAnArray;
    LinearListTable* linlistTab = new LinearListTable;
    OrderedTable* OrdTab = new OrderedTable;
    AVLTreeTable* AVLTab = new AVLTreeTable;
    OpenHashTable* opHashTab = new OpenHashTable(50);
    HashTable* hashTab = new HashTable;
    tables->push_back(linArrTab);
    tables->push_back(linlistTab);
    tables->push_back(OrdTab);
    tables->push_back(AVLTab);
    tables->push_back(opHashTab);
    tables->push_back(hashTab);
    tabWin = new TableWindow(this, tables);

}

MainWindow::~MainWindow()
{
    for (auto tab: *tables)
    {
        delete tab;
    }
    delete[] tables;
    delete ui;
}


void MainWindow::on_pushCalculateButton_clicked()
{
   /* string input;
        // получаем выражение от пользователя
    std::stringstream streamData(ui->centralwidget->text().toStdString());
    getline(streamData, input);

        // шаблоны для разбора мономов и операций
        string term_pattern = R"((-?\d+)?([a-z]+)(\^\d+)?)";
        string op_pattern = R"(\s*([\+\*])\s*)";

        // итераторы для поиска мономов и операций
        size_t pos = 0;
        size_t term_end = input.find_first_of(")*", pos);
        size_t op_pos = input.find_first_of(")*", pos + 1);
        vector<string> terms;
        vector<char> ops;
        while (pos < input.length()) {
            // получаем следующий моном
            string term = input.substr(pos, term_end - pos);
            terms.push_back(term);
            // получаем следующую операцию (если она есть)
            if (op_pos < input.length()) {
                ops.push_back(input[op_pos]);
            }
            // переходим к следующему моному и операции
            pos = term_end;
            term_end = input.find_first_of(")*", pos + 1);
            op_pos = input.find_first_of(")*", pos + 2);
        }

        // обходим мономы, парсим коэффициенты и степени переменных
        vector<int> coefs;
        vector<string> vars;
        vector<vector<int>> powers;
        for (const string& term : terms) {
            size_t coef_end = term.find_first_of("abcdefghijklmnopqrstuvwxyz");
            string coef_str = term.substr(0, coef_end);
            int coef = coef_str.length() > 0 ? stoi(coef_str) : 1;
            coefs.push_back(coef);
            size_t vars_start = coef_end;
            size_t power_start = term.find_first_of('^', vars_start);
            while (vars_start < term.length()) {
                string var = term.substr(vars_start, power_start - vars_start);
                vars.push_back(var);
                if (power_start < term.length()) {
                    string power_str = term.substr(power_start + 1);
                    vector<int> var_powers;
                    for (char& c : power_str) {
                        var_powers.push_back(c - '0');
                    }
                    powers.push_back(var_powers);
                } else {
                    vector<int> var_powers(var.length(), 1);
                    powers.push_back(var_powers);
                }
                vars_start = power_start + 1;
                power_start = term.find_first_of('^', vars_start);
            }
        }

        // выводим полученные данные
        for (int i = 0; i < coefs.size(); i++) {
            cout << coefs[i] << "*";
            for (int j = 0; j < vars.size(); j++) {
                if (j > 0) {
                    cout << "*";
                }
                if (vars[j].length() > 1) {
                    cout << "(" << vars[j] << ")";
                } else {
                    cout << vars[j];
                }
                cout << "^" << powers[i][j];
            }
            if (i < ops.size()) {
                cout << " " << ops[i] << " ";
            }
        }
        cout << endl;*/
}


void MainWindow::on_pushOpenTableButton_clicked()
{
    if (!tabWin->isHidden())
        QMessageBox::warning(this, "What are you doing?", "Table allready opened");
    else
    {
        tabWin->setCurTab(ui->comboBox->currentIndex());
        tabWin->show();
    }
}

