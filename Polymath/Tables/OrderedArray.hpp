#include <vector>
using namespace std;

#include "TableInterface.hpp"
#include "MyExeptions.hpp"

class OrderedTable : public TableInterface{
private:
    vector<pair<string, Poly*>> OrdArray;

public:
    OrderedTable() {}
       
    
    void addPolynomial(const std::string& _key, Poly* const _polynomial) override {
        // ищем позицию, на которую нужно вставить новый элемент, с помощью бинарного поиска
        int left = 0, right = OrdArray.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (OrdArray[mid].first == _key) {
                throw AddException("A polynomial with this name is already in the table");
            }
            else if (OrdArray[mid].first < _key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        // вставляем новый элемент на найденную позицию
        OrdArray.insert(OrdArray.begin() + left, { _key, _polynomial });
    }

    void deletePolynomial(const std::string& _key) override {
        int temp = -1;
        vector<pair<string, Poly*>> tempArray;
        if (OrdArray.size() == 0)
            throw EmptyTableException("Empty table");

        int left = 0, right = OrdArray.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (OrdArray[mid].first == _key) {
                temp = mid;
                break;
            }
            else if (OrdArray[mid].first < _key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        for (int i = 0; i < temp; i++) {
            tempArray.push_back(OrdArray[i]);
        }
        for (int i = temp+1; i < OrdArray.size(); i++) {
            tempArray.push_back(OrdArray[i]);
        }
        OrdArray = move(tempArray);
        if (temp == -1)
            throw NothingFoundException("No polynomial found with this key");
    }
    
    Poly searchPolynomial(const std::string& _key) {
        int temp = -1;
        int left = 0, right = OrdArray.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (OrdArray[mid].first == _key) {
                return *OrdArray[mid].second;
            }
            else if (OrdArray[mid].first < _key) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (temp == -1)
            throw NoPolyException("Полином с таким ключом не найден");
    }
};
