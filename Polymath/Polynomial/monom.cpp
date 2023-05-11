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
    if (_deg != nullptr) {
        deg = degree_array({ _deg[0], _deg[1], _deg[2] });
    } else {
        deg = degree_array({ 0, 0, 0 });
    }
}

Monom::Monom(const double other, const degree_array& _deg)
{
    coeff = other;
    deg = _deg;
}

Monom::~Monom() { }

double Monom::getCoeff() const
{
    return coeff;
}

int Monom::getDegree(int index) const
{
    if (index >= 0 && index < DEGREE_COUNT) { return deg[index]; }
    else { throw invalid_argument("Error: index out of range"); }
}

void Monom::setCoeff(const double& _coef)
{
    coeff = _coef;
}

void Monom::setDegree(const int& _index, const int& _degree)
{
    deg[_index] = _degree;
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

Monom Monom::operator+(const Monom& other) const
{
    if (ratio(other)) { return Monom(coeff + other.coeff, deg); }
    else { throw invalid_argument("Error: degree arrays are not equal"); }
}

Monom Monom::operator-(const Monom& other) const
{
    if (ratio(other)) { return Monom(coeff - other.coeff, deg); }
    else { throw invalid_argument("Error: degree arrays are not equal"); }
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

Monom Monom::DerX() const
{
    if (deg[0] == 0) { throw invalid_argument("Error: degree of x is 0"); }

    double new_coeff = coeff * deg[0];
    array<int, 3> new_degree = { deg[0] - 1, deg[1], deg[2] };

    return Monom(new_coeff, new_degree);
}

Monom Monom::DerY() const
{
    if (deg[1] == 0) { throw invalid_argument("Error: degree of y is 0"); }

    double new_coeff = coeff * deg[1];
    array<int, 3> new_degree = { deg[0], deg[1] - 1, deg[2] };

    return Monom(new_coeff, new_degree);
}

Monom Monom::DerZ() const
{
    if (deg[2] == 0) { throw invalid_argument("Error: degree of z is 0"); }

    double new_coeff = coeff * deg[2];
    array<int, 3> new_degree = { deg[0], deg[1], deg[2] - 1 };

    return Monom(new_coeff, new_degree);
}

string Monom::Print() const
{
    ostringstream out;
    if (coeff == 0) { return "0"; }
    if (coeff != 1 || (coeff == 1 && deg[0] == 0 && deg[1] == 0 && deg[2] == 0)) { out << coeff; }
    if (deg[0] > 0) { out << "x"; }
    if (deg[0] > 1) { out << "^" << deg[0]; }
    if (deg[1] > 0)
    {
        if (deg[0] > 0) { out << "*"; }
        out << "y";
    }
    if (deg[1] > 1) { out << "^" << deg[1]; }
    if (deg[2] > 0)
    {
        if (deg[0] > 0 || deg[1] > 0) { out << "*"; }
        out << "z";
    }
    if (deg[2] > 1) { out << "^" << deg[2]; }
    return out.str();
}
