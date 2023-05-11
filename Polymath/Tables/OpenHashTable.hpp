#ifndef OpenHashTable_hpp
#define OpenHashTable_hpp

#include "poly.hpp"
#include "TableInterface.hpp"
#include "MyExcepions.hpp"

#include <vector>

struct PolyData
{
    string key;
    Poly* polynomial;
};

class OpenHashTable : public TableInterface
{
private:
    size_t size;
    vector<vector<PolyData>> data;

    size_t iSearch(const string& key) const { return hash<string>{ }(key) % size; }
public:
    
    explicit OpenHashTable(const size_t _size) : size(_size), data(_size) {}
    
    void addPolynomial(const string& key, Poly* const polynomial) override
    {
        PolyData obj = { key, polynomial };
        size_t i = iSearch(key);

        if (!data[i].empty()) { throw AddException("Элемент с ключом уже существует"); }

        data[i].push_back(obj);
    }

    void deletePolynomial(const string& key) override
    {
        size_t i = iSearch(key);

        auto& vec = data[i];
        auto it = find_if(vec.begin(), vec.end(), [key](const PolyData& obj) { return obj.key == key; });

        if (it == vec.end()) { throw NoPolyException("Элемент с ключом не найден"); }

        vec.erase(it);
    }

    Poly searchPolynomial(const string& key)
    {
        size_t i = iSearch(key);

        const auto& vec = data[i];
        auto it = find_if(vec.begin(), vec.end(), [key](const PolyData& obj) { return obj.key == key; });

        if (it != vec.end()) { return *(it->polynomial); }

        throw NothingFoundException("Элемент с ключом не найден");
    }
};

#endif /* OpenHashTable_hpp */
