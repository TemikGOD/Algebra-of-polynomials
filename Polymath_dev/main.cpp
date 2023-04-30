#include "monom.hpp"
#include "poly.hpp"
//#include "linearListTable.hpp"

#include <iostream>
#include <string>

/*
 
 Программа предназначена для выполнения алгебраических операций над полиномами с тремя переменными.

 1. Полиномы хранятся в виде списка;
 2. Полиномы хранятся во всех таблицах одновременно, ключом является имя;
 3. Таблиц должно быть 6 видов:
    - Линейная на массиве.
    - Линейная на списке. (+)
    - Упорядоченная на массиве.
    - На поисковом дереве (АВЛ).
    - Хеш-таблица с открытым перемешиванием.
    - Хеш-таблица со списками (Метод цепочек).
    - Активная (выбранная пользователем) таблица должна выводиться на экран в формате двух столбов:
      1. Имя полинома.
      2. Строковое представление полинома.
 
 Операции над таблицами:
 1. Добавление полинома (Во всех сразу),
 2. Удаление полинома (Во всех сразу),
 3. Поиск (Только в активной таблице; Выполняется в процессе вычисления выражений, составленных из имен полиномов);

 https://github.com/TemikGOD
 Интерфейс.
 Линейная таблица на массиве.
 Таблица на поисковом дереве (АВЛ).

 https://github.com/wsemnazlo
 Полином. (-)
 Линейная таблица на списке. (+)
 Хеш-таблица с открытым перемешиванием.
 Общий интерфейс таблиц. (+)

 https://github.com/savchukPR
 Постфикс для полиномов.
 Упорядоченная таблица на массиве.
 Хеш-таблица со списками.
 
*/

using namespace std;

int main(int argc, const char * argv[]) {
    
    int* d = new int(3);
    d[0] = 3; d[1] = 2; d[2] = 2;
    
    Monom monom(6, d);
    cout << "First monom: "; cout << monom.Print() << ", ";
    
    Monom monom2(5, d);
    cout << "Second monom: "; cout << monom2.Print() << "; " << endl;
    
    Monom monom3;
    cout << "1. +: "; monom3 = monom + monom2; cout << monom3.Print() << endl;
    cout << "2. -: "; monom3 = monom - monom2; cout << monom3.Print() << endl;
    cout << "3. *: "; monom3 = monom * monom2; cout << monom3.Print() << endl;
    cout << "4. /: "; monom3 = monom / monom2; cout << monom3.Print() << endl << endl;
    
    Monom monom4;
    cout << "5. x': "; monom4 = monom.DerX(monom); cout << monom4.Print() << endl;
    cout << "6. y': " ;monom4 = monom.DerY(monom); cout << monom4.Print() << endl;
    cout << "7. z': "; monom4 = monom.DerZ(monom); cout << monom4.Print() << endl << endl;
    
    Monom monom5(4, d);

    List<Monom> list; list.push_back(monom5); list.push_back(monom);
    Poly polynom(list); cout << "First poly: "; cout << polynom.Print() << ", ";
    
    List<Monom> list2; list2.push_back(monom2); list2.push_back(monom);
    Poly polynom2(list2); cout << "Second poly: "; cout << polynom2.Print() << "; " << endl;
    
    Poly polynom3;
    cout << "1. point: "; polynom3.Point(1, 2, 3); cout << polynom3.Print() << endl;

    return 0;
}

