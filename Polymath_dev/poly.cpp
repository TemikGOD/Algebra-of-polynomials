#include "poly.hpp"
#include "list.hpp"

#include <math.h>

/*
 
 Реализация класса полиномов.
 
 Реализованы методы:
 1. Сложения полиномов. (?)
 
 2. Вычитания полиномов.
 3. Деление полиномов.
 4. Умножения полиномов.
 5. Умножения полинома на константу.
 
 6. Вычисление в точке. (+)
 
 7. Нахождения производной.
 
*/

using namespace std;

Poly::Poly(const Poly& _poly) { list.copy(_poly.list); }

Poly::Poly(List<Monom> _list) { list.copy(_list); }

Poly& Poly::operator=(const Poly& _poly) { list.copy(_poly.list); return *this; }

string Poly::Print()
{
    ostringstream out; bool per = true; List<Monom> copy; copy.copy(list);
    while(!copy.isEmpty()) { Monom monom; monom = copy.pop_back();
        if(!per && monom.check() >= 0) { out << "+"; } per = false; out << monom.Print(); } return out.str();
}

double Poly::Point(double _x, double _y, double _z)
{
    double result = 0; List<Monom> cpylist; cpylist.copy(list);
    while (!cpylist.isEmpty()) { Monom monom; monom = cpylist.pop_back();
        double coef = monom.check();
        int x = monom.deg[0];
        int y = monom.deg[1];
        int z = monom.deg[2];
        result += coef * pow(_x, x) * pow(_y, y) * pow(_z, z); }
    return result;
}
