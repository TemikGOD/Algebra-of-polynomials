# ТЗ

## Введение

### Наименование программы

Наименование программы: "Polymath"

### Назначение

Программа предназначена для выполнения алгебраических операций над полиномами с тремя переменными.


### Требования к программе

#### Общие требования 

1. Полиномы хранятся в виде списка;
2. Полиномы хранятся во всех таблицах одновременно, ключом является имя;
3. Таблиц должно быть 6 видов:
    - Линейная на массиве,
    - Линейная на списке,
    - Упорядоченная на массиве,
    - На поисковом дереве (АВЛ),
    - Хеш-таблица с открытым перемешиванием,
    - Хеш-таблица со списками (Метод цепочек);
4. Активная (выбранная пользователем) таблица должна выводиться на экран в формате двух столбов: 
    - Имя полинома,
    - Строковое представление полинома;

#### Требования к функциональным характеристикам

Программа должна обеспечивать возможность выполнения перечисленных функций:

1. Операции над отдельным полиномом:
    - Вычисление в точке,
    - Умножение на константу,
    - Производная;
2. Операции в выражениях из полиномов:
    - Сложение,
    - Вычитание,
    - Умножение на константу,
    - Умножение полиномов,
    - Деление полиномов;
        * операции должны выполняться, используя постфиксную форму.
3. операции над таблицами: 
    - Добавление полинома (Во всех сразу),
    - Удаление полинома (Во всех сразу),
    - Поиск (Только в активной таблице; Выполняется в процессе вычисления выражений, составленных из имен полиномов);

#### Требования к надёжности

Отказы программы вследствие некорректных действий пользователя при взаимодействии с программой недопустимы.

### Сведения о команде разработки

- <https://github.com/TemikGOD>

Интерфейс. Линейная таблица на массиве. Таблица на поисковом дереве (АВЛ).

- <https://github.com/vadimbelan>

Полином. Линейная таблица на списке. Хеш-таблица с открытым перемешиванием. Общий интерфейс таблиц.

- <https://github.com/savchukPR>

Постфикс для полиномов. Упорядоченная таблица на массиве. Хеш-таблица со списками.

### Собрания

Собрание команды разработчиков с заказчиком по четвергам в 14 40.

Собрание разработчиков между собой по воскресеньям в 19 00.

### Стадии и этапы разработки

#### Стадии разработки

Разработка должна быть проведена в шесть стадий:

| Стадии разработки | Выполнение |
|---------------------|----------|
| Разработка технического задания |:heavy_check_mark:|
|Выписывание и описание списков объектов и основных алгоритмов |  |
|Подготовка проекта программной системы |  |
|Разработка пустых версий модульных тестов для методов разработанных классов |  |
|Разработка тестов и кода | |
|Сдача проекта заказчику |  |

#### Этапы разработки

1. На стадии разработки технического задания должен быть выполнен этап разработки, согласования и утверждения настоящего технического задания;

2. На стадии выписывания и описания списоков объектов и основных алгоритмов должны быть выполнены перечисленные этапы работ:

    1. Подготовка списка объектов в markdown,
    2. Размещение списка в Readme репозитория на гитхабе,
    3. Подготовка по каждому объекту описания модели,
    4. По каждому алгоритму либо подготавливается описание, либо даются ссылки, где это описание можно найти,
    5. Презентация заказчику;

3. На стадии подготовки проекта программной системы должны быть выполнены заготовки классов в h-файле и заготовки форм в Visual Studio;

4. На стадии разработки пустых версий модульных тестов для методов разработанных классов использовать библиотеку google tests;

5. На стадии разработки тестов и кода нужно написать код, который будет проходить сборку и все тесты;

6. На стадии сдачи проекта заказчику нужно презентовать проект, защитить его и сдать документацию заказчику.
