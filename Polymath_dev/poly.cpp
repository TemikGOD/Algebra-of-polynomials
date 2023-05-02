#include "poly.hpp"
#include "list.hpp"

#include <math.h>

/*
 
 Реализация класса полиномов.
 (Страдает вывод в строку)
 
 Реализованы методы:
 1. Сложения полиномов. (+)
 4. Умножения полиномов. (+)
 5. Умножения полинома на константу. (+)
 6. Вычисление в точке. (+)
 3. Деление полиномов. (?)
 
 2. Вычитания полиномов. (-)
 7. Нахождения производной. (-)
 
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

Poly Poly::operator+(const Poly& _poly)
{
    Poly res;
    List<Monom> copy1, copy2;
    copy1.copy(list);
    copy2.copy(_poly.list);
    while(!copy1.isEmpty() && !copy2.isEmpty())
    {
        Monom monom1 = copy1.pop_front();
        Monom monom2 = copy2.pop_front();
        if(monom1.getDegree() > monom2.getDegree())
        {
            res.list.push_back(monom1);
            copy2.push_front(monom2);
        }
        else if(monom1.getDegree() < monom2.getDegree())
        {
            res.list.push_back(monom2);
            copy1.push_front(monom1);
        }
        else
        {
            Monom sum = monom1 + monom2;
            if(sum.getCoeff() != 0)
                res.list.push_back(sum);
        }
    }
    while(!copy1.isEmpty())
    {
        res.list.push_back(copy1.pop_front());
    }
    while(!copy2.isEmpty())
    {
        res.list.push_back(copy2.pop_front());
    }
    return res;
}

Poly Poly::operator*(const Poly& _poly)
{
    Poly res;
    List<Monom> copy1, copy2;
    copy1.copy(list);
    copy2.copy(_poly.list);
    while(!copy1.isEmpty())
    {
        Monom monom1 = copy1.pop_front();
        List<Monom> temp;
        while(!copy2.isEmpty())
        {
            Monom monom2 = copy2.pop_front();
            Monom mul = monom1 * monom2;
            if(mul.getCoeff() != 0)
                temp.push_back(mul);
        }
        copy2.copy(_poly.list);
        Poly tempPoly(temp);
        res = res + tempPoly;
    }
    return res;
}

Poly Poly::operator*(const double _coeff)
{
    Poly res;
    List<Monom> copy;
    copy.copy(list);
    while(!copy.isEmpty())
    {
        Monom monom = copy.pop_front();
        Monom mul = monom * _coeff;
        if(mul.getCoeff() != 0)
            res.list.push_back(mul);
    }
    return res;
}

/*

Poly Poly::operator/(Poly& _poly)
{
    Poly res;
    if(_poly.list.isEmpty())
        throw runtime_error("Division by zero");
    List<Monom> copy1, copy2;
    copy1.copy(list);
    copy2.copy(_poly.list);
    while(!copy1.isEmpty() && copy1.getFront().getDegree() >= copy2.getFront().getDegree())
    {
        Monom monom1 = copy1.pop_front();
        Monom monom2 = copy2.getFront();
        Monom div = monom1 / monom2;
        res.list.push_back(div);
        //Poly tempPoly(List<Monom>({div}));
        Poly temp = tempPoly * _poly;
        //copy1 = copy1 - temp.list;
    }
    return res;
}
 
*/

/*

Poly Poly::operator+(const double _coeff)
{
    Poly res;
    List<Monom> copy;
    copy.copy(list);
    Monom monom(_coeff, 0);
    while(!copy.isEmpty())
    {
        Monom temp = copy.pop_front();
        if(temp.getDegree() == 0)
        {
            monom = monom + temp;
        }
        else
        {
            res.list.push_back(temp);
        }
    }
    if(monom.getCoeff() != 0)
        res.list.push_back(monom);
    return res;
}
 
*/

/*

Poly Poly::operator-(const Poly& _poly)
{
    Poly res;
    List<Monom> copy1, copy2;
    copy1.copy(list);
    copy2.copy(_poly.list);
    while(!copy1.isEmpty() && !copy2.isEmpty())
    {
        Monom monom1 = copy1.pop_front();
        Monom monom2 = copy2.pop_front();
        if(monom1.getDegree() > monom2.getDegree())
        {
            res.list.push_back(monom1);
            copy2.push_front(-monom2);
        }
        else if(monom1.getDegree() < monom2.getDegree())
        {
            res.list.push_back(-monom2);
            copy1.push_front(monom1);
        }
        else
        {
            Monom diff = monom1 - monom2;
            if(diff.getCoeff() != 0)
                res.list.push_back(diff);
        }
    }
    while(!copy1.isEmpty())
    {
        res.list.push_back(copy1.pop_front());
    }
    while(!copy2.isEmpty())
    {
        res.list.push_back(-copy2.pop_front());
    }
    return res;
}
 
*/

double Poly::Point(double _x, double _y, double _z) {
    double result = 0; List<Monom> copy; copy.copy(list);
    while (!copy.isEmpty()) { Monom monom; monom = copy.pop_back();
        double coef = monom.check();
        int x = monom.deg[0];
        int y = monom.deg[1];
        int z = monom.deg[2];
        result += coef * pow(_x, x) * pow(_y, y) * pow(_z, z); }
    cout << result << endl;
    return result;
}
