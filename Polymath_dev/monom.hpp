#ifndef monom_hpp
#define monom_hpp

#include "sstream"

/*
 
 Объявления класса мономов.
 
 Хранятся:
 1. Коэффициенты. (+)
 2. Cтепени. (+)
 
 Объвлены методы:
 1. Сложения мономов. (+)
 2. Вычитания мономов. (+)
 3. Умножения мономов. (+)
 4. Деление мономов. (+)
 5. Нахождения производных X, Y, Z. (+)
 
*/

using namespace std;

class Monom {
private:
    double coeff; int deg[3]; bool ratio(Monom t_monom);
protected:
    double check();
public:
    Monom(); Monom(const Monom& monom); Monom(double _сoeff, int* _deg); ~Monom(); string Print();
        
    Monom operator=(const Monom& _monom);
    
    Monom operator+(const Monom& _monom);
    Monom operator-(const Monom& _monom);
    Monom operator/(const Monom& _monom);
    
    Monom operator*(const Monom& _monom);
    Monom operator*(double _coeff);
    
    Monom DerX(const Monom _monom); Monom DerY(const Monom _monom); Monom DerZ(const Monom _monom);
    
    friend class Poly;
};

#endif /* monom_hpp */
