#ifndef OpenHashTable_hpp
#define OpenHashTable_hpp

#include "poly.hpp"
#include "interface.hpp"
#include "MyExcepions.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

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
    
    void addPolynomial(const string& key, Poly* const polynomial)
    {
        PolyData obj = { key, polynomial };
        size_t i = iSearch(key);
        if (!data[i].empty()) { throw AddExeption("Element with key already exists"); }
        data[i].push_back(obj);
    }

    void deletePolynomial(const std::string& key)
    {
        size_t i = iSearch(key);
        auto& vec = data[i];
        auto it = find_if(vec.begin(), vec.end(), [key](const PolyData& obj) { return obj.key == key; });
        if (it == vec.end()) { throw NoPolyExeption("Element with key key not found"); }
        vec.erase(it);
    }

    Poly searchPolynomial(const std::string& key) const
    {
        size_t i = iSearch(key);
        const auto& vec = data[i];
        auto it = find_if(vec.begin(), vec.end(), [key](const PolyData& obj) { return obj.key == key; });
        if (it != vec.end()) { return *(it->polynomial); }
        throw NothingFoundExeption("Element with key not found");
    }
};

#endif /* OpenHashTable_hpp */
