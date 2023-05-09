#ifndef poly_hpp
#define poly_hpp

#include "monom.hpp"
#include <list>

class Poly
{
private:
    std::list<Monom> list;
public:
    Poly() { };
    Poly(const Poly& _poly);
    Poly(const std::list<Monom>& _list);
    ~Poly() { }
    
    Poly& operator=(const Poly& other);
    
    Poly operator+(const Poly& other) const;
    Poly operator+(const double other) const;
    
    Poly operator-(const Poly& other) const;
    //Poly operator-(const double other) const;
    
    Poly operator*(const Poly& other) const;
    Poly operator*(const double other) const;
    
    Poly operator/(const Poly& other) const;

    double Point(double _x, double _y, double _z) const;
    
    Poly Derivative() const;
    
    string Print() const;
};

#endif /* poly_hpp */
