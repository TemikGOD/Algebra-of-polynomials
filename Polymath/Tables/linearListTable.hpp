#ifndef linearListTable_hpp
#define linearListTable_hpp

#include "interface.hpp"
#include "list.hpp"
#include "MyExcepions.hpp"

//#include <stdexcept>

using namespace std;

class LinearListTable : public TableInterface {
private:
    List<pair<string, Poly*>> items;

public:
    LinearListTable() { }

    bool isPolynomialInTable(const string& key)
    {
        List<pair<string, Poly*>> copy;
        copy.copy(items);

        while (!copy.isEmpty()) {
            if (copy.pop_back().first == key) {
                return true;
            }
        }

        throw NothingFoundExeption("Polynomial not found in table");
    }

    void addPolynomial(const string& _key, Poly* const _polynomial)
    {
        string key = _key;

        if (isPolynomialInTable(key)) {
            throw AddExeption("Polynomial already exists in table");
        }
    }
    
    void deletePolynomial(const string& key)
    {
        if (items.isEmpty())
        {
            throw EmptyTableExeption("Table is empty");
        }

        List<pair<string, Poly*>> copy;
        copy.copy(items);

        while (!copy.isEmpty())
        {
            pair<string, Poly*> item = copy.pop_back();
            if (item.first == key) { items.remove(items.find(item)); return; }
        }

        throw NoPolyExeption("Polynomial not found in table");
    }
    
    Poly searchPolynomial(const string& key)
    {
        List<pair<string, Poly*>> copy;
        copy.copy(items);

        while (!copy.isEmpty()) {
            pair<string, Poly*> item = copy.pop_back();
            if (item.first == key) {
                return *item.second;
            }
        }

        throw NothingFoundExeption("Polynomial not found in table");
    }
};


#endif /* linearListTable_hpp */
