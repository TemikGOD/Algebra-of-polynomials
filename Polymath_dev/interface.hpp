#ifndef interface_hpp
#define interface_hpp

#include <string>
#include <vector>

/*
 
 Виртуальный класс таблиц.
 Является интерфейсом для остальных таблиц.
 
*/

using namespace std;

template<typename T>
class Interface
{
public:
    virtual void addPolynomial(const T _key) = 0;
    virtual void deletePolynomial(const T _key) = 0;
protected:
    virtual T search(const string key) = 0;
    virtual bool isInTable(const T _key) = 0;
};

#endif /* interface_hpp */
