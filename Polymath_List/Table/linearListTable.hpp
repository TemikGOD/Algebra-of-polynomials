#ifndef linearListTable_hpp
#define linearListTable_hpp

#include "TableInterface.hpp"
#include "MyExceptions.hpp"

class LinearListTable : public TableInterface
{
private:
    List<std::pair<std::string, Poly*>> items;

    bool isPolynomialInTable(const std::string& key) const
    {
        for (const auto& item : items) { if (item.first == key) { return true; } }
        return false;
    }

public:
    LinearListTable() {}

    void addPolynomial(const std::string& key, Poly* polynomial)
    {
        if (isPolynomialInTable(key)) { throw AddException("Polynomial already exists in table"); }
        items.push_back(std::make_pair(key, polynomial));
    }

    void deletePolynomial(const std::string& key)
    {
        if (items.isEmpty()) { throw EmptyTableException("Table is empty"); }

        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it->first == key)
            {
                items.pop_front();
                return;
            }
        }
        throw NoPolyException("Polynomial not found in table");
    }

    Poly searchPolynomial(const std::string& key) const
    {
        for (const auto& item : items) { if (item.first == key) { return *(item.second); } }
        throw NothingFoundException("Polynomial not found in table");
    }
};

#endif /* linearListTable_hpp */
