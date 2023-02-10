# ТЗ

## Введение

### Наименование программы

Наименование программы: "Useless program"

### Назначение

Программа предназначена для выполнения алгебраических операций над полиномами от трех переменных.

### Требования к программе

#### Требования к функциональным характеристикам

Программа должна обеспечивать возможность выполнения перечисленных ниже функций:

1. полиномы хранятся в виде списка
2. полиномы хранятся во всех таблицах одновременно, ключом является имя;
3. таблиц должно быть 6 видов: 
    - линейная на массиве
    - линейная на списке
    - упорядоченная на массиве 
    - дерево (авл или красно-черное)
    - две хэш-таблицы;
4. Операции над отдельным полиномом:
    - вычисление в точке
    - умножение на константу
    - производная
    - интеграл
5. Операции в выражениях из полиномов:
    - сложение
    - вычитание
    - умножение на константу
    - умножение полиномов
    - деление полиномов
        * операции должны выполняться, используя постфиксную форму
6. операции над таблицами: 
    - добавление полинома (во все сразу)
    - удаление полинома (во всех сразу)
    - поиск (только в активной таблице, выполняется в процессе вычисления выражений, составленных из имен полиномов)
7. активная (выбранная пользователем) таблица должна выводиться на экран в формате, как минимум, двух столбцов: 
    - имя полинома
    - строковое представление полинома
  
#### Требования к надёжности

Отказы программы вследствие некорректных действий пользователя при взаимодействии с программой недопустимы.

### Стадии и этапы разработки

#### Стадии разработки

Разработка должна быть проведена в шесть стадий:

1. разработка технического задания
2. выписывание и описание списоков объектов и основных алгоритмов 
3. подготовка проекта программной системы
4. разработка пустых версий модульных тестов для методов разработанных классов
5. разработка тестов и кода
6. сдача проекта заказчику

#### Этапы разработки

1. На стадии разработки технического задания должен быть выполнен этап разработки, согласования и утверждения настоящего технического задания.

2. На стадии выписывания и описания списоков объектов и основных алгоритмов должны быть выполнены перечисленные ниже этапы работ:

    1. подготовка списка объектов в markdown 
    2. размещение списка в Readme репозитория на гитхабе
    3. подготовка по каждому объекту описания модели 
    4. По каждому алгоритму либо подготавливается описание, либо даются ссылки, где это описание можно найти
    5. презентация заказчику

3. На стадии подготовки проекта программной системы должны быть выполнены заготовки классов в h-файле и заготовки форм в Visual Studio

4. На стадии разработки пустых версий модульных тестов для методов разработанных классов использовать библиотеку google tests

5. На стадии разработки тестов и кода нужно написать код, который будет проходить сборку и все тесты

6. На стадии сдачи проекта заказчику нужно презентовать проект, защитить его и сдать документацию заказчику
