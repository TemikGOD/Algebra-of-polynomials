#pragma once
class TableInterface
{
protected:
	unsigned int key;
	virtual void addPolynomial(const Polynomial& _pol) = 0;
	virtual void deletePolynomial(const Polynomial& _pol) = 0;
	virtual Polynomial search(const unsigned int& _key) = 0;
	virtual bool isInTable(const Polynomial& _pol) = 0;
};


