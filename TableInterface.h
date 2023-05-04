#pragma once
#include <string>

class TableInterface
{
public:
    virtual void addPolynomial(const std::string& _key, const Poly* _polynomial) = 0;
    virtual void deletePolynomial(const std::string& _key) = 0;
    virtual Poly searchPolynomial(const std::string& _key) = 0;
};


