#include "poly.hpp"
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

Poly::Poly(const Poly& other) : list(other.list) { }

Poly::Poly(const std::list<Monom>& _list) : list(_list) { }

Poly& Poly::operator=(const Poly& other)
{
    list = other.list;
    return *this;
}

Poly Poly::operator+(const Poly& other) const // Постфиксная запись оператора "+"
{
    Poly res;

    std::stack<Monom> stack1;
    for (auto it = list.begin(); it != list.end(); ++it) { stack1.push(*it); }

    std::stack<Monom> stack2;
    for (auto it = other.list.begin(); it != other.list.end(); ++it) { stack2.push(*it); }

    while (!stack1.empty() && !stack2.empty())
    {
        Monom monom1 = stack1.top();
        Monom monom2 = stack2.top();

        if (monom1.getDegree() > monom2.getDegree())
        {
            res.list.push_front(monom1);
            stack1.pop();
        }
        else if (monom1.getDegree() < monom2.getDegree())
        {
            res.list.push_front(monom2);
            stack2.pop();
        }
        else
        {
            Monom sum = monom1 + monom2;

            if (sum.getCoeff() != 0) { res.list.push_front(sum); }
            stack1.pop();
            stack2.pop();
        }
    }

    while (!stack1.empty()) { res.list.push_front(stack1.top()); stack1.pop(); }
    while (!stack2.empty()) { res.list.push_front(stack2.top()); stack2.pop(); }

    return res;
}

Poly Poly::operator+(const double other) const // Постфиксная запись операции "+" с константой
{
    Poly res;
    std::stack<Monom> st;

    int deg[3] = { 0, 0, 0 };

    Monom monom(other, deg);
    st.push(monom);

    std::list<Monom> copy = list; // Создаем копию объекта list

    while (!copy.empty()) {
        st.push(copy.front());
        copy.pop_front();
    }

    while (!st.empty()) {
        res.list.push_front(st.top());
        st.pop();
    }

    return res;
}


Poly Poly::operator*(const Poly& other) const // Постфиксная запись операции "*"
{
    Poly res;
    std::stack<Poly> st;
    std::list<Monom> copy1 = list;

    while (!copy1.empty())
    {
        Monom monom1 = copy1.front();
        copy1.pop_front();

        std::list<Monom> temp;
        std::list<Monom> copy2 = other.list;

        while (!copy2.empty())
        {
            Monom monom2 = copy2.front();
            copy2.pop_front();

            Monom mul = monom1 * monom2;

            if (mul.getCoeff() != 0) { temp.push_back(mul); }
        }
        st.push(Poly(temp));
    }

    while (st.size() > 1)
    {
        Poly p1 = st.top();
        st.pop();
        Poly p2 = st.top();
        st.pop();
        st.push(p1 + p2);
    }

    if (!st.empty()) { res = st.top(); }
    return res;
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
        else { out << " - "; }
        out << it->Print();
    }
    return out.str();
}