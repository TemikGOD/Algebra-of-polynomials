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

    virtual ~LinearListTable()
    {
        for (const auto &del: items)
            delete del.second;
        items.clear();
    }

    Poly getPol(int index) override {auto it = items.begin(); std::advance(it, index); return *it->second; };
    string getKey(int index) override {auto it = items.begin(); std::advance(it, index); return it->first; };

    void addPolynomial(const string& key, Poly* polynomial) override
    {
        if (isPolynomialInTable(key)) { throw AddException("Polynomial already exists in table"); }
        items.emplace_back(key, polynomial);
    }

    void deletePolynomial(const string& key) override
    {
        if (items.empty()) { throw EmptyTableException("Table is empty"); }
        
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            if (it->first == key) { items.erase(it); return; }
        }
        throw NoPolyException("Polynomial not found in table");
    }

    Poly searchPolynomial(const string& key) override
    {
        for (const auto& item : items) { if (item.first == key) { return *item.second; } }
        throw NothingFoundException("Polynomial not found in table");
    }
};

#endif /* linearListTable_hpp */
