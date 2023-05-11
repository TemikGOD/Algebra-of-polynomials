#ifndef TableInterface_hpp
#define TableInterface_hpp

#include "../Polynomial/poly.hpp"

class TableInterface
{
public:
    virtual void addPolynomial(const string& _key, Poly* const _polynomial) = 0;
    virtual void deletePolynomial(const string& _key) = 0;
    virtual Poly searchPolynomial(const string& _key) = 0;
    virtual ~TableInterface() = 0;
    virtual Poly getPol(int index) = 0;
    virtual string getKey(int index) = 0;
};

#endif /* TableInterface_hpp */
