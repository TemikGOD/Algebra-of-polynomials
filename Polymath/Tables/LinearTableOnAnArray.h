#pragma once
#include "TableInterface.h"
#include <vector>
#include <exception>
#include "poly.hpp"
#include "MyExceptions.h"

class LinearTableOnAnArray :protected TableInterface
{
private:
	struct tableRow
	{
		std::string key;
		Poly* value;

		tableRow(const std::string _key, Poly* const _value)
		{
			key = _key;
			value = _value;
		}
	};

	std::vector<tableRow> table;

public:
	LinearTableOnAnArray() = default;
	size_t size() const noexcept { return table.size(); }
	Poly operator[](size_t poz) { return *table[poz].value; }

	Poly searchPolynomial(const std::string& _key) override
	{
		for (int i = 0; i < table.size(); i++)
			if (table[i].key == _key)
				return *table[i].value;
		throw NothingFoundExeption("Nothing found");
	}

	void addPolynomial(const std::string& _key, Poly* const _pol) override
	{
		bool addedCheck = false;
		try
		{
			searchPolynomial(_key);
		}
		catch (const NothingFoundExeption&)
		{
			table.push_back(tableRow(_key, _pol));
			addedCheck = true;
		}
		if (!addedCheck)
		{
			throw AddExeption("A polynomial with this name is already in the table");
		}
	}

	void deletePolynomial(const std::string& _key) override
	{
		if (this->size() == 0)
			throw EmptyTableExeption("There is nothing in the table");
		int poz = -1;
		try
		{	
			for (int i = 0; i < table.size(); i++)
				if (table[i].key == _key)
					poz = i;
			if (poz == -1)
				throw NothingFoundExeption("Nothing found");
		}
		catch (const NothingFoundExeption&)
		{
			throw NoPolyExeption("There is no polynomial with this name in the table");
		}
		table[poz] = table[size() - 1];
		table.pop_back();
	}

};

