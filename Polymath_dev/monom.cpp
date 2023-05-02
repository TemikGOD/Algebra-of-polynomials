#include "monom.hpp"

/*
 
 Реализация класса мономов.
  
 Реализованы методы:
 1. Сложения мономов. (+)
 2. Вычитания мономов. (+)
 3. Умножения мономов. (+)
 4. Деление мономов. (+)
 5. Нахождения производных X, Y, Z. (+)
 
*/

using namespace std;

double Monom::check() { return coeff; }

Monom::Monom()
{
    coeff = 0.0; for (int i = 0; i < 2; i++) { deg[i] = 0; }
}

Monom::Monom(const Monom& monom)
{
    coeff = monom.coeff;
    for (int i = 0; i < 3; i++) { deg[i] = monom.deg[i]; }
}

Monom::Monom(double _coeff, int* _deg)
{
    coeff = _coeff;
    for (int i = 0; i < 3; i++) { deg[i] = _deg[i]; }
}

Monom::~Monom() { }

bool Monom::ratio(Monom monom)
{
    return (deg[0] == monom.deg[0] && deg[1] == monom.deg[1] && deg[2] == monom.deg[2]);
}

string Monom::Print()
{
    stringstream out; out << coeff;
    if (deg[0] != 0) out << "x^" << deg[0];
    if (deg[1] != 0) out << "*y^" << deg[1];
    if (deg[2] != 0) out << "*z^" << deg[2];
    return out.str();
}

Monom Monom::operator=(const Monom& _monom)
{
    coeff = _monom.coeff;
    deg[0] = _monom.deg[0];
    deg[1] = _monom.deg[1];
    deg[2] = _monom.deg[2];
    return *this;
}

Monom Monom::operator+(const Monom& _monom)
{
    if (ratio(_monom)) return Monom(coeff + _monom.coeff, deg); else throw invalid_argument("Error");
}

Monom Monom::operator-(const Monom& _monom)
{
    if (ratio(_monom)) return Monom(coeff - _monom.coeff, deg); else throw invalid_argument("Error");
}

Monom Monom::operator*(const Monom& _monom)
{
    return Monom(coeff * _monom.coeff, new int[3] { deg[0] + _monom.deg[0], deg[1] + _monom.deg[1], deg[2] + _monom.deg[2] });
}

Monom Monom::operator*(double _coeff) { return Monom(coeff * _coeff, deg); }

Monom Monom::operator/(const Monom& _monom)
{
    return Monom(coeff / _monom.coeff, new int[3]{ deg[0] - _monom.deg[0], deg[1] - _monom.deg[1], deg[2] - _monom.deg[2] });
}

Monom Monom::DerX(const Monom _monom)
{
    int newD[] = { deg[0], deg[1], deg[2] };
    if (_monom.deg[0] > 0) { newD[0]--; return Monom(coeff * _monom.deg[0] , newD); } else throw::invalid_argument("Error");
}

    
Monom Monom::DerY(const Monom _monom)
{
    int newD[] = { deg[0], deg[1], deg[2] };
    if (_monom.deg[1] > 0) { newD[1]--; return Monom(coeff * _monom.deg[1] , newD); } else throw::invalid_argument("Error");
}
    
Monom Monom::DerZ(const Monom _monom)
{
    int updateDeg[] = { deg[0], deg[1], deg[2] };
    if (_monom.deg[2] > 0) { updateDeg[2]--; return Monom(coeff * _monom.deg[2] , updateDeg); } else throw::invalid_argument("Error");
};
