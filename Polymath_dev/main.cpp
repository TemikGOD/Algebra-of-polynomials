#include "monom.hpp"
#include "poly.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Коэффициенты мономов
    const int arr[] = {3, 2, 2};
    const Monom monom1(6, arr);
    const Monom monom2(5, arr);
    const Monom monom5(-5, arr);

    cout << "Первый моном: " << monom1.Print() << endl;
    cout << "Второй моном: " << monom2.Print() << endl << endl;
    
    // Мономы
    Monom monom3;
    monom3 = monom1 + monom2; cout << "1. Сумма мономов: " << monom3.Print() << endl;
    monom3 = monom1 - monom2; cout << "2. Разность мономов: " << monom3.Print() << endl;
    monom3 = monom1 * monom2; cout << "3. Произведение мономов:: " << monom3.Print() << endl;
    try { monom3 = monom1 / monom2; cout << "4. Частное мономов: " << monom3.Print() << endl; }
    catch (const invalid_argument& e) { cerr << "Ошибка: " << e.what() << endl; }
    
    Monom monom4;
    monom4 = monom1.DerX(monom1); cout << "5. Производная X первого монома: " << monom4.Print() << endl;
    monom4 = monom1.DerY(monom1); cout << "6. Производная Y первого монома: " << monom4.Print() << endl;
    monom4 = monom1.DerZ(monom1); cout << "7. Производная Z первого монома: " << monom4.Print() << endl << endl;
    
    // Полиномы
    List<Monom> list1;
    list1.push_back(monom5); list1.push_back(monom1);
    Poly polynom1(list1);
    cout << "Первый полином: " << polynom1.Print() << endl;
    
    List<Monom> list2;
    list2.push_back(monom2); list2.push_back(monom1);
    Poly polynom2(list2);
    cout << "Второй полином: " << polynom2.Print() << endl << endl;
    
    Poly polynom4 = polynom1 + polynom2; cout << "1. Сумма полиномов: " << polynom4.Print() << endl;
    polynom4 = polynom1 - polynom2; cout << "2. Разность полиномов: " << polynom4.Print() << endl;
    polynom4 = polynom1 * polynom2; cout << "3. Произведение полиномов: " << polynom4.Print() << endl;
    polynom4 = polynom1 / polynom1; cout << "4. Частное полиномов: " << polynom4.Print() << endl;
    
    List<Monom> list5;
    list5.push_back(monom5);
    Poly polynom5(list5);
    cout << "5. Умножение полинома на константу: " << polynom5.Print();
    polynom5 = polynom5 * 4; cout << " * 4 = " << polynom5.Print() << endl;
    cout << "6. Сумма полинома и константы: " << polynom5.Print() << " + 4 = ";
    polynom5 = polynom5 + 4; cout << polynom5.Print() << endl << endl;
    
    List<Monom> list3;
    list3.push_back(monom5); list3.push_back(monom1);
    Poly polynom3(list3);
    cout << "Третий полином: " << polynom3.Print() << endl;
    
    cout << "Результат третьего полинома в точке: " << polynom3.Point(1, 2, 3) << endl << endl;
    
    return 0;
}


