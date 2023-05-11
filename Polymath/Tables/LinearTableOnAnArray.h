#pragma once
#include "TableInterface.hpp"
#include <vector>
#include <exception>
#include "MyExcepions.hpp"

class LinearTableOnAnArray :public TableInterface
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

        ~tableRow()
        {
            delete value;
        }
	};

	std::vector<tableRow> table;

public:
	LinearTableOnAnArray() = default;
	size_t size() const noexcept { return table.size(); }
	Poly operator[](size_t poz) { return *table[poz].value; }

    virtual ~LinearTableOnAnArray()
    {
        for (auto del: table)
            del.~tableRow();
        table.clear();
    }

    Poly getPol(int index) override { return *table[index].value; }
    string getKey(int index) override { return table[index].key; }

	Poly searchPolynomial(const std::string& _key) override
	{
        for (auto i = 0; i < table.size(); i++)
			if (table[i].key == _key)
				return *table[i].value;
        throw NothingFoundException("Nothing found");
	}

	void addPolynomial(const std::string& _key, Poly* const _pol) override
	{
		bool addedCheck = false;
		try
		{
			searchPolynomial(_key);
		}
        catch (NothingFoundException& exp)
		{
			table.push_back(tableRow(_key, _pol));
			addedCheck = true;
		}
		if (!addedCheck)
		{
            throw AddException("A polynomial with this name is already in the table");
		}
	}

	void deletePolynomial(const std::string& _key) override
	{
		if (this->size() == 0)
            throw EmptyTableException("There is nothing in the table");
		int poz = -1;
		try
		{	
			for (int i = 0; i < table.size(); i++)
				if (table[i].key == _key)
					poz = i;
			if (poz == -1)
                throw NothingFoundException("Nothing found");
		}
        catch (const NothingFoundException&)
		{
            throw NoPolyException("There is no polynomial with this name in the table");
		}
		table[poz] = table[size() - 1];
		table.pop_back();
	}

};

