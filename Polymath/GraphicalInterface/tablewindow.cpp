#include "tablewindow.h"
#include "ui_tablewindow.h"
#include "../Polynomial/poly.hpp"


TableWindow::TableWindow(QWidget *parent, vector<TableInterface*>* _tables) :
    QDialog(parent),
    ui(new Ui::TableWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel;
    QStringList horizontalHeader;
    horizontalHeader.append("Key");
    horizontalHeader.append("Polynomial");
    model->setHorizontalHeaderLabels(horizontalHeader);
    tables = _tables;

    for(auto row: tables[currentTable])
    {

    }

}

TableWindow::~TableWindow()
{
    delete ui;
}

std::pair<int, std::string> extractDegree(std::string term) {
    int degree = 0;
    std::size_t pos = term.find("^");
    if (pos != std::string::npos) {
        degree = std::stoi(term.substr(pos + 1));
        term = term.substr(0, pos);
    }
    return std::make_pair(degree, term);
}

Poly stringToPoly(std::string str) {
    Poly poly;
    std::istringstream iss(str);
    std::string monomStr;
    while (std::getline(iss, monomStr, '+')) {
        std::istringstream issMonom(monomStr);
        Monom monom;
        monom.setCoeff(1.0);
        monom.setDegree(0, 0);
        monom.setDegree(1, 0);
        monom.setDegree(2, 0);
        std::string term;
        while (std::getline(issMonom, term, ' ')) {
            if (term.empty()) {
                continue;
            }
            if (term.find("x") != std::string::npos) {
                auto [degree, rest] = extractDegree(term);
                monom.setDegree(0, degree);
                if (!rest.empty() && rest.find("y") != std::string::npos) {
                    auto [degree2, rest2] = extractDegree(rest);
                    monom.setDegree(1, degree2);
                    if (!rest2.empty() && rest2.find("z") != std::string::npos) {
                        auto [degree3, _] = extractDegree(rest2);
                        monom.setDegree(2, degree3);
                    }
                    else {
                        monom.setDegree(2, 0);
                    }
                }
                else {
                    monom.setDegree(1, 0);
                    monom.setDegree(2, 0);
                }
            }
            else if (term.find("y") != std::string::npos) {
                auto [degree, rest] = extractDegree(term);
                monom.setDegree(1, degree);
                if (!rest.empty() && rest.find("z") != std::string::npos) {
                    auto [degree2, _] = extractDegree(rest);
                    monom.setDegree(2, degree2);
                }
                else {
                    monom.setDegree(0, 0);
                    monom.setDegree(2, 0);
                }
            }
            else if (term.find("z") != std::string::npos) {
                auto [degree, _] = extractDegree(term);
                monom.setDegree(2, 0);
                monom.setDegree(0, 0);
                monom.setDegree(1, 0);
            }
            else {
                monom.setCoeff(std::stod(term));
            }
        }
        poly.list.push_back(monom);
    }
    return poly;
}

unsigned int TableWindow::getCurTab() { return currentTable; };
void TableWindow::setCurTab(unsigned int _currentTable) { currentTable = _currentTable; };

void TableWindow::on_pushAddButton_clicked()
{
    std::string pol;
    std::string key;
    try
    {
        pol = ui->linePolynomialEdit->text().toStdString();
        key = ui->lineKeyEdit->text().toStdString();
        for(auto &tab: *tables)
        {
            Poly* polynomial = new Poly;
            *polynomial = stringToPoly(ui->linePolynomialEdit->text().toStdString());
            tab->addPolynomial(key, polynomial);
        }
    }
    catch (...) {
        throw;
    }
    item = new QStandardItem(QString::fromStdString(key));
    model->setItem(tables[currentTable].size(), 0, item);
    item = new QStandardItem(QString::fromStdString(pol));
    model->setItem(tables[currentTable].size(), 1, item);
    ui->tableView->setModel(model);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
}

