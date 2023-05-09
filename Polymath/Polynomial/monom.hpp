#ifndef monom_hpp
#define monom_hpp

#include "sstream"
#include <array>

using namespace std;

class Monom {
private:
    static const int DEGREE_COUNT = 3;
    using degree_array = array<int, DEGREE_COUNT>;
    degree_array deg;
    double coeff;
    
    bool ratio(const Monom& other) const;
public:
    Monom();
    Monom(const Monom& other);
    Monom(double _coeff, const int* _deg = nullptr);
    Monom(const double other, const degree_array& _deg);
    ~Monom();

    double getCoeff() const;
    int getDegree(int index = 0) const;
    
    Monom& operator=(const Monom& other);
    
    Monom operator+(const Monom& other) const;
    Monom operator-(const Monom& other) const;
    
    Monom operator*(const Monom& other) const;
    Monom operator*(double other) const;
    
    Monom operator/(const Monom& other) const;
    
    Monom DerX() const;
    Monom DerY() const;
    Monom DerZ() const;
    
    string Print() const;
    
    friend class Poly;
};

#endif /* monom_hpp */
