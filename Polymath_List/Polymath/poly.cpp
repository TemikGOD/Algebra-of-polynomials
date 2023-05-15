#include "poly.hpp"
#include <iostream>
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
        Monom monom1 = copy1.front();
        Monom monom2 = copy2.front();

        if (monom1.getDegree() > monom2.getDegree())
        {
            res.list.push_back(monom1);
            copy1.pop_front();
        }
        else if (monom1.getDegree() < monom2.getDegree())
        {
            res.list.push_back(monom2);
            copy2.pop_front();
        }
        else
        {
            Monom sum = monom1 + monom2;

            if (sum.getCoeff() != 0) { res.list.push_back(sum); }
            copy1.pop_front();
            copy2.pop_front();
        }
    }

    while (!copy1.isEmpty()) { res.list.push_back(copy1.front()); copy1.pop_front(); }
    while (!copy2.isEmpty()) { res.list.push_back(copy2.front()); copy2.pop_front(); }
    return res;
}

Poly Poly::operator+(const double other) const
{
    Poly res;
    List<Monom> copy = list;

    int deg[3] = {0, 0, 0};

    Monom monom(other, deg);
    res.list.push_back(monom);

    while (!copy.isEmpty()) { Monom monom = copy.front(); res.list.push_back(monom); copy.pop_front(); }
    return res;
}

Poly Poly::operator-(const Poly& other) const
{
    Poly res;
    List<Monom> copy1 = list;
    List<Monom> copy2 = other.list;

    while (!copy1.isEmpty() || !copy2.isEmpty())
    {
        if (copy1.isEmpty() || copy1.front().getDegree() < copy2.front().getDegree())
        {
            Monom neg = copy2.front() * -1.0;
            if (neg.getCoeff() != 0) { res.list.push_back(neg); }
            copy2.pop_front();
        }
        else if (copy2.isEmpty() || copy1.front().getDegree() > copy2.front().getDegree())
        {
            res.list.push_back(copy1.front());
            copy1.pop_front();
        }
        else
        {
            Monom diff = copy1.front() - copy2.front();
            if (diff.getCoeff() != 0) { res.list.push_back(diff); }
            copy1.pop_front();
            copy2.pop_front();
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
        Monom monom1 = copy1.front();
        copy1.pop_front();

        List<Monom> temp;
        List<Monom> copy2 = other.list;

        while (!copy2.isEmpty())
        {
            Monom monom2 = copy2.front();
            copy2.pop_front();

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
        Monom monom = copy.front();
        copy.pop_front();

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

    while (!remainder.list.isEmpty() && remainder.list.front().getDegree() >= other.list.front().getDegree())
    {
        int coeff = static_cast<int>(remainder.list.front().getCoeff() / other.list.front().getCoeff());
        int degree = remainder.list.front().getDegree() - other.list.front().getDegree();

        Monom monom(coeff, { degree, 0, 0 });

        if (remainder.list.front().getCoeff() != coeff * other.list.front().getCoeff())
        {
            throw runtime_error("Non-integral result of division");
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
    double result = 0;
    List<Monom> copy = list;

    while (!copy.isEmpty())
    {
        Monom monom = copy.back();
        copy.pop_back();

        double coef = monom.getCoeff();
        int x = monom.getDegree(0);
        int y = monom.getDegree(1);
        int z = monom.getDegree(2);

        result += coef * pow(_x, x) * pow(_y, y) * pow(_z, z);
    }

    return result;
}

std::string Poly::Print() const
{
    std::ostringstream out;
    if (list.isEmpty()) { return "0"; }
    auto it = list.begin();
    out << it->Print();
    ++it;
    for (; it != list.end(); ++it)
    {
        if (it->getCoeff() > 0) { out << " + "; }
        out << it->Print();
    }
    return out.str();
}
