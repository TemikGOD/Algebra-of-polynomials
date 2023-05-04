#pragma once
#include <string>
class TableInterface
{
public:
	virtual void addPolynomial(const std::string& _key) = 0;
	virtual void deletePolynomial(const int& _key) = 0;
protected:
	virtual Polynomial search(const std::string& _key) = 0;
	virtual bool isInTable(const std::string& _key) = 0;
};


