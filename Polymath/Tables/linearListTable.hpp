#ifndef linearListTable_hpp
#define linearListTable_hpp

#include "TableInterface.hpp"
#include "MyExcepions.hpp"

class LinearListTable : public TableInterface
{
private:
    list<pair<string, Poly*>> items;
    
    bool isPolynomialInTable(const string& key)
    {
        if (items.empty()) { return false; }
        for (const auto& item : items) { if (item.first == key) { return true; } }
        return false;
    }
public:
    LinearListTable() {}

    void addPolynomial(const string& key, Poly* polynomial)
    {
        if (isPolynomialInTable(key)) { throw AddException("Polynomial already exists in table"); }
        items.emplace_back(key, polynomial);
    }

    void deletePolynomial(const string& key)
    {
        if (items.empty()) { throw EmptyTableException("Table is empty"); }
        
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it->first == key) { items.erase(it); return; }
        }
        throw NoPolyException("Polynomial not found in table");
    }

    Poly searchPolynomial(const string& key)
    {
        for (const auto& item : items) { if (item.first == key) { return *item.second; } }
        throw NothingFoundException("Polynomial not found in table");
    }
};

#endif /* linearListTable_hpp */
