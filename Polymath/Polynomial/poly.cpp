#include "poly.hpp"
#include "list.hpp"

#include <array>
#include <math.h>

using namespace std;

Poly::Poly(const Poly& other) : list(other.list) { }

Poly::Poly(const List<Monom>& _list) : list(_list) { }

Poly& Poly::operator=(const Poly& other)
{
    list = other.list;
    return *this;
}

Poly Poly::operator+(const Poly& other) const
{
    Poly res;
    List<Monom> copy1 = list;
    List<Monom> copy2 = other.list;
    
    while (!copy1.isEmpty() && !copy2.isEmpty())
    {
        Monom monom1 = copy1.pop_front();
        Monom monom2 = copy2.pop_front();
        
        if (monom1.getDegree() > monom2.getDegree())
        {
            res.list.push_back(monom1);
            copy2.push_front(monom2);
        }
        else if (monom1.getDegree() < monom2.getDegree())
        {
            res.list.push_back(monom2);
            copy1.push_front(monom1);
        }
        else
        {
            Monom sum = monom1 + monom2;
            if (sum.getCoeff() != 0) { res.list.push_back(sum); }
        }
    }
    while (!copy1.isEmpty()) { res.list.push_back(copy1.pop_front()); }
    
    while (!copy2.isEmpty()) { res.list.push_back(copy2.pop_front()); }
    
   return res;
}

Poly Poly::operator+(const double other) const
{
    Poly res;
    List<Monom> copy = list;
    
    int deg[3] = {0, 0, 0};
    
    Monom monom(other, deg);
    res.list.push_back(monom);
    
    while (!copy.isEmpty()) { Monom monom = copy.pop_front(); res.list.push_back(monom); }
    
    return res;
}

Poly Poly::operator-(const Poly& other) const
{
    Poly res;
    List<Monom> copy1 = list;
    List<Monom> copy2 = other.list;
    
    while (!copy1.isEmpty() || !copy2.isEmpty())
    {
        if (copy1.isEmpty() || copy1.getHead()->getValue().getDegree() < copy2.getHead()->getValue().getDegree())
        {
            Monom neg = copy2.pop_front() * -1.0;
            if (neg.getCoeff() != 0) { res.list.push_back(neg); }
        }
        else if (copy2.isEmpty() || copy1.getHead()->getValue().getDegree() > copy2.getHead()->getValue().getDegree()) { res.list.push_back(copy1.pop_front()); }
        else
        {
            Monom diff = copy1.pop_front() - copy2.pop_front();
            if (diff.getCoeff() != 0) { res.list.push_back(diff);
            }
        }
    }
    return res;
}

Poly Poly::operator*(const Poly& other) const
{
    Poly res;
    List<Monom> copy1 = list;
    
    while (!copy1.isEmpty())
    {
        Monom monom1 = copy1.pop_front();
        List<Monom> temp;
        List<Monom> copy2 = other.list;
        
        while (!copy2.isEmpty())
        {
            Monom monom2 = copy2.pop_front();
            Monom mul = monom1 * monom2;
            
            if (mul.getCoeff() != 0) { temp.push_back(mul); }
        }
        res = res + Poly(temp);
    }
    
    return res;
}

Poly Poly::operator*(const double other) const
{
    Poly res;
    List<Monom> copy = list;
    
    while (!copy.isEmpty())
    {
        Monom monom = copy.pop_front();
        Monom mul = monom * other;
        if (mul.getCoeff() != 0) { res.list.push_back(mul); }
    }
    
    return res;
}

Poly Poly::operator/(const Poly& other) const
{
    if (other.list.isEmpty()) { throw runtime_error("Division by zero"); }

    Poly remainder(*this);
    Poly quotient;

    while (!remainder.list.isEmpty() && remainder.list.getHead()->getValue().getDegree() >= other.list.getHead()->getValue().getDegree())
    {
        int coeff = static_cast<int>(remainder.list.getHead()->getValue().getCoeff() / other.list.getHead()->getValue().getCoeff());
        int degree = remainder.list.getHead()->getValue().getDegree() - other.list.getHead()->getValue().getDegree();
        
        Monom monom(coeff, array<int, 3>({ degree, 0, 0 }));
        
        // проверяем, является ли результат деления мономов целым числом
        if (remainder.list.getHead()->getValue().getCoeff() != coeff * other.list.getHead()->getValue().getCoeff())
        {
            throw std::runtime_error("Non-integral result of division");
        }
        
        quotient.list.push_back(monom);
        List<Monom> monomList;
        monomList.push_back(monom);
        Poly temp(monomList);
        temp = temp * other;
        remainder = remainder - temp;
    }
    
    return quotient;
}

double Poly::Point(double _x, double _y, double _z) const
{
    double result = 0; List<Monom> copy; copy.copy(list);
    while (!copy.isEmpty()) { Monom monom; monom = copy.pop_back();
        double coef = monom.coeff;
        int x = monom.deg[0];
        int y = monom.deg[1];
        int z = monom.deg[2];
        result += coef * pow(_x, x) * pow(_y, y) * pow(_z, z); }
    return result;
}

string Poly::Print() const
{
    ostringstream out;
    bool per = true;
    
    List<Monom> copy;
    copy.copy(list);
    
    while (!copy.isEmpty())
    {
        Monom monom = copy.pop_back();
        
        if (monom.getCoeff() == 0) { continue; }
        
        if (!per && monom.getCoeff() >= 0) { out << "+"; }
        
        per = false;
        out << monom.Print();
    }
    
    if (per) { out << "0"; }
    return out.str();
}
