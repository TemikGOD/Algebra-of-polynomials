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
    double coeff; int deg[3]; bool ratio(Monom _monom);
protected:
    double check();
public:
    
    float getCoeff() { return coeff; }
    void setCoeff(float c) { coeff = c; }
    int getDegree(int index = 0) {
        if(index >= 3) {
            // обработка ошибки: индекс выходит за пределы массива deg
            return -1; // или выбросить исключение
        }
        return deg[index];
    }
    
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
