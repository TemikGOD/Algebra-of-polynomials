#ifndef TableInterface_hpp
#define TableInterface_hpp

#include "poly.hpp"

class TableInterface
{
public:
    virtual void addPolynomial(const string& _key, Poly* const _polynomial) = 0;
    virtual void deletePolynomial(const string& _key) = 0;
    virtual Poly searchPolynomial(const string& _key) = 0;
};

#endif /* TableInterface_hpp */
