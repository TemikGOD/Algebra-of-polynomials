#include "poly.hpp"
#include <iostream>
#include <math.h>
#include "Postfix.hpp"

using namespace std;

Poly::Poly(const Poly& other) : list(other.list) { }

Poly::Poly(const std::list<Monom>& _list) : list(_list) { }

Poly& Poly::operator=(const Poly& other)
{
    list = other.list;
    return *this;
}

Poly Poly::operator-(const Poly& other) const
{
    Poly res;
    std::list<Monom> copy1 = list;
    std::list<Monom> copy2 = other.list;

    while (!copy1.empty() || !copy2.empty())
    {
        if (copy1.empty() || copy1.front().getDegree() < copy2.front().getDegree())
        {
            Monom neg = copy2.front() * -1.0;
            if (neg.getCoeff() != 0) { res.list.push_back(neg); }
            copy2.pop_front();
        }
        else if (copy2.empty() || copy1.front().getDegree() > copy2.front().getDegree())
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

Poly Poly::operator*(const double other) const
{
    Poly res;
    std::list<Monom> copy = list;

    while (!copy.empty())
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
    if (other.list.empty()) { throw runtime_error("Division by zero"); }

    Poly remainder(*this);
    Poly quotient;

    while (!remainder.list.empty() && remainder.list.front().getDegree() >= other.list.front().getDegree())
    {
        int coeff = static_cast<int>(remainder.list.front().getCoeff() / other.list.front().getCoeff());
        int degree = remainder.list.front().getDegree() - other.list.front().getDegree();

        Monom monom(coeff, std::array<int, 3>({ degree, 0, 0 }));

        if (remainder.list.front().getCoeff() != coeff * other.list.front().getCoeff())
        {
            throw runtime_error("Non-integral result of division");
        }

        quotient.list.push_back(monom);
        std::list<Monom> monomList;
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
    std::list<Monom> copy = list;

    while (!copy.empty())
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

Poly Poly::Derivative() const
{
    std::list<Monom> derivs;

    for (const auto& monom : list)
    {
        try
        {
            Monom deriv(0, {0, 0, 0});
            deriv = deriv + monom.DerX();
            deriv = deriv + monom.DerY();
            deriv = deriv + monom.DerZ();

            if (deriv.getCoeff() != 0) { derivs.push_back(deriv); }
        }
        catch (std::invalid_argument& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    if (derivs.empty()) { derivs.push_back(Monom(0)); }

    return Poly(derivs);
}

std::string Poly::Print() const
{
    std::ostringstream out;
    if (list.empty()) { return "0"; }
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
