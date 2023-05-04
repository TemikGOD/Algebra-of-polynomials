//
//  interface.hpp
//  Polymath project
//

#ifndef interface_hpp
#define interface_hpp

#include <string>

using namespace std;

template<typename Poly>
class Interface
{
public:
    virtual void addPolynomial(Poly other) = 0;
    virtual void deletePolynomial(const string& key) = 0;
    virtual bool isPolynomialInTable(const string& key) = 0;
    virtual Poly searchPolynomial(const string& key) = 0;
};

#endif /* interface_hpp */
