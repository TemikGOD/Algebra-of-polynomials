#include "monom.hpp"

using namespace std;

Monom::Monom()
{
    coeff = 0.0; for (int i = 0; i < 3; i++) { deg[i] = 0; }
}

Monom::Monom(const Monom& other)
{
    coeff = other.coeff; for (int i = 0; i < 3; i++) { deg[i] = other.deg[i]; }
}

Monom::Monom(double other, const int* _deg)
{
    coeff = other;
    deg = degree_array({ _deg[0], _deg[1], _deg[2] });
}

Monom::Monom(const double other, const degree_array& _deg)
{
    coeff = other;
    deg = _deg;
}

Monom::~Monom() { }

void Monom::setCoeff(double c)
{
    coeff = c;
}

double Monom::getCoeff() const
{
    return coeff;
}

int Monom::getDegree(int index) const
{
    if (index >= 0 && index < DEGREE_COUNT) { return deg[index]; }
    else { throw std::invalid_argument("Error: index out of range"); }
}

bool Monom::ratio(const Monom& other) const
{
    return (deg[0] == other.deg[0] && deg[1] == other.deg[1] && deg[2] == other.deg[2]);
}

Monom& Monom::operator=(const Monom& other)
{
    coeff = other.coeff; deg[0] = other.deg[0]; deg[1] = other.deg[1]; deg[2] = other.deg[2];
    return *this;
}

Monom& Monom::operator+=(const Monom& other)
{
    if (ratio(other)) { coeff += other.coeff; }
    return *this;
}

Monom& Monom::operator-=(const Monom& other)
{
    if (ratio(other)) { coeff -= other.coeff; }
    return *this;
}

Monom& Monom::operator*=(const Monom& other)
{
    coeff *= other.coeff;
    deg[0] += other.deg[0];
    deg[1] += other.deg[1];
    deg[2] += other.deg[2];
    return *this;
}

Monom Monom::operator+(const Monom& other) const
{
    if (ratio(other)) { return Monom(coeff + other.coeff, deg); }
    else { throw std::invalid_argument("Error: degree arrays are not equal"); }
}

Monom Monom::operator-(const Monom& other) const
{
    if (ratio(other)) { return Monom(coeff - other.coeff, deg); }
    else { throw std::invalid_argument("Error: degree arrays are not equal"); }
}

Monom Monom::operator*(const Monom& other) const
{
    return Monom(coeff * other.coeff, degree_array {
        deg[0] + other.deg[0],
        deg[1] + other.deg[1],
        deg[2] + other.deg[2] });
}

Monom Monom::operator*(double other) const { return Monom(coeff * other, deg); }

Monom Monom::operator/(const Monom& other) const
{
    return Monom(coeff / other.coeff, degree_array {
        deg[0] - other.deg[0],
        deg[1] - other.deg[1],
        deg[2] - other.deg[2] });
}

Monom Monom::DerX(const Monom&) const
{
    if (deg[0] > 0) { return Monom(coeff * deg[0], degree_array({ deg[0] - 1, deg[1], deg[2] })); }
    else { throw invalid_argument("Error: degree of x is 0"); }
}

Monom Monom::DerY(const Monom&) const
{
    if (deg[1] > 0) { return Monom(coeff * deg[1], degree_array({ deg[0], deg[1] - 1, deg[2] })); }
    else { throw std::invalid_argument("Error: degree of y is 0"); }
}

Monom Monom::DerZ(const Monom&) const
{
    if (deg[2] > 0) { return Monom(coeff * deg[2], degree_array({ deg[0], deg[1], deg[2] - 1 })); }
    else { throw std::invalid_argument("Error: degree of z is 0"); }
}

string Monom::Print() const
{
    std::stringstream ss;
    ss << coeff;
    if (deg[0] > 0) { ss << "x^" << deg[0]; }
    if (deg[1] > 0) { ss << "*y^" << deg[1]; }
    if (deg[2] > 0) { ss << "*z^" << deg[2]; }
    return ss.str();
}

