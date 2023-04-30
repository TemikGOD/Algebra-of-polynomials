#ifndef poly_hpp
#define poly_hpp

#include "monom.hpp"
#include "list.hpp"

/*
 
 Объявления класса полиномов.
 
 Хранится:
 1. Список мономов. (+)
 
 Объвлены методы:
 1. Сложения полиномов. (+)
 2. Вычитания полиномов. (+)
 
 3. Деление полиномов. (+)
 
 4. Умножения полиномов. (+)
 5. Умножения полинома на константу. (+)
 
 6. Вычисление в точке. (+)
 
 7. Нахождения производной.
 
*/

using namespace std;

class Poly {
private:
    List<Monom> list;
public:
    Poly() { }; Poly(const Poly& _poly); Poly(List<Monom> _list); ~Poly() { } string Print();
    
    Poly& operator=(const Poly& _poly);
    
    Poly operator+(Poly _poly);
    Poly operator-(Poly _poly);
    Poly operator/(Poly _poly);
    
    Poly operator*(Poly _poly);
    Poly operator*(double _coeff);
    
    double Point(double _x, double _y, double _z);
};

#endif /* poly_hpp */
