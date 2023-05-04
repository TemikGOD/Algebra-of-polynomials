#ifndef linearListTable_hpp
#define linearListTable_hpp

#include "interface.hpp"
#include "list.hpp"

//#include <stdexcept>

using namespace std;

template<typename Poly>
class LinearListTable : public Interface<Poly> {
private:
    List<pair<string, Poly>> items;

public:
    LinearListTable() { }

    // Добавляет многочлен в таблицу
    void addPolynomial(Poly other) override
    {
        string key = other.first;
        items.push_back(make_pair(key, other));
    }

    // Удаляет многочлен из таблицы
    void deletePolynomial(const string& key) override
    {
        List<pair<string, Poly>> copy;
        copy.copy(items);

        while (!copy.isEmpty())
        {
            pair<string, Poly> item = copy.pop_back();
            if (item.first == key) { items.remove(items.find(item)); return; }
        }

        throw out_of_range("Key not found");
    }

    // Проверяет, есть ли многочлен в таблице
    bool isPolynomialInTable(const string& key) override
    {
        List<pair<string, Poly>> copy;
        copy.copy(items);

        while (!copy.isEmpty()) { if (copy.pop_back().first == key) { return true; } }

        return false;
    }

    // Ищет многочлен по ключу
    Poly searchPolynomial(const string& key) override
    {
        List<pair<string, Poly>> copy;
        copy.copy(items);

        while (!copy.isEmpty())
        {
            pair<string, Poly> item = copy.pop_back();
            if (item.first == key) { return item.second; }
        }

        throw out_of_range("Key not found");
    }
};


#endif /* linearListTable_hpp */
