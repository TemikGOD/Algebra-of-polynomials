#include <vector>
using namespace std;

#include "TableInterface.hpp"
#include "MyExeptions.hpp"

class OrderedTable : public TableInterface{
private:
    vector<pair<string, Poly*>> OrdArray;

    void SortTable(vector<pair<string, Poly*>>& vec, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        SortTable(vec, left, mid);
        SortTable(vec, mid + 1, right);

        vector<pair<string, Poly*>> left_vec(vec.begin() + left, vec.begin() + mid + 1);
        vector<pair<string, Poly*>> right_vec(vec.begin() + mid + 1, vec.begin() + right + 1);

        int i = 0, j = 0;
        for (int k = left; k <= right; k++) {
            if (j >= right_vec.size() || (i < left_vec.size() && left_vec[i].first <= right_vec[j].first)) {
                vec[k] = left_vec[i++];
            }
            else {
                vec[k] = right_vec[j++];
            }
        }


    }
public:
    OrderedTable() {}
       
    
    void addPolynomial(const std::string& _key, Poly* const _polynomial) override {
        bool addedCheck = false;
        try
        {
            searchPolynomial(_key);
        }
        catch (const NothingFoundException&)
        {
            OrdArray.push_back({ _key, _polynomial });
            SortTable(OrdArray, 0, OrdArray.size() - 1);
            addedCheck = true;
        }
        if (!addedCheck)
        {
            throw AddException("A polynomial with this name is already in the table");
        }
    }

    void deletePolynomial(const std::string& _key) override {
        int temp = -1;
        if (OrdArray.size() == 0)
            throw EmptyTableException("Empty table");

        for (int i = 0; i < OrdArray.size(); i++) {
            if (OrdArray[i].first == _key) {
                OrdArray.erase(OrdArray.begin() + i);
                temp = 1;
            }
        }
        if (temp == -1)
            throw NothingFoundException("No polynomial found with this key");
    }
    
    Poly searchPolynomial(const std::string& _key) {
        int temp = -1;
        for (int i = 0; i < OrdArray.size(); i++) {
            if (OrdArray[i].first == _key) {
                return *OrdArray[i].second;
                temp = 1;
            }
        }
        if (temp == -1)
            throw NoPolyException("Полином с таким ключом не найден");
    }
};
