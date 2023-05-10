#include <vector>
#include <list>
#include <utility>
#include <string>
#include "poly.hpp"
#include "TableInterface.hpp"
#include "MyExeptions.hpp"

using namespace std;

class HashTable : public TableInterface{
public:
    HashTable() : size(100), table(size) {}
    HashTable(int _size) : size(_size), table(size) {}

    void addPolynomial(const std::string& _key, Poly* const _polynomial) {
        int index = hashFunction(_key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == _key) {
                it->second = _polynomial;
                return;
            }
        }
        table[index].push_back(std::make_pair(_key, _polynomial));
        count++;
        if (count > size * loadFactor) {
            resize();
        }
    }

    void deletePolynomial(const std::string& _key) {
        if (count == 0) {
            throw EmptyTableException("Cannot delete polynomial from an empty table.");
        }
        int index = hashFunction(_key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == _key) {
                table[index].erase(it);
                count--;
                return;
            }
        }
        throw NothingFoundException("Cannot delete polynomial with Key not found.");
    }

    Poly searchPolynomial(const std::string& _key) {
        if (count == 0) {
            throw EmptyTableException("Cannot search for polynomial in an empty table.");
        }
        int index = hashFunction(_key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == _key) {
                if (it->second == nullptr) {
                    throw NoPolyException("Cannot return polynomial not found.");
                }
                return *it->second;
            }
        }
        throw NothingFoundException("Cannot return polynomial with Key not found.");
    }

private:
    const double loadFactor = 0.75;
    int size;
    int count = 0;
    vector<list<pair<string, Poly*>>> table;

    int hashFunction(const string& _key) {
        int hash = 0;
        for (char c : _key) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

    void resize() {
        size *= 2;
        vector<list<pair<string, Poly*>>> newTable(size);
        for (auto& bucket : table) {
            for (auto& item : bucket) {
                int index = hashFunction(item.first);
                newTable[index].push_back(item);
            }
        }
        table = newTable;
    }
};