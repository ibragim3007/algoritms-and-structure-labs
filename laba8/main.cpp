#include <iostream>
#include "SplashList.h"
#include "List.h"

using namespace std;

template<class T>
void workSplash (SplashList<T> & stl) {
    int answer = 0;
    while (answer != 10) {
        cout << "\n1. Добавить элемент в конец"
                "\n2. Удалить элемент с конца"
                "\n3. Очистить"
                "\n4. Просмотреть список"
                "\n5. Добавить элемент в голову"
                "\n6. Удалить элемент с головы"
                "\n7. Удалить по индексу"
                "\n8. Добавить по индексу"
                "\n9. Проверить на пустоту"
                "\n10. Выйти" << endl;
        cout << "> "; cin >> answer;
        if (answer == 1) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            stl.pushBack(value);
        }
        else if (answer == 2) stl.popBack();
        else if (answer == 3) stl.clear();
        else if (answer == 4) stl.print();
        else if (answer == 5) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            stl.pushHead(value);
        }
        else if (answer == 6) stl.popFront();
        else if (answer == 7) {
            int value;
            cout << "\nВведите индекс: "; cin >> value;
            stl.deleteAt(value);
        }
        else if (answer == 8) {
            int index;
            T value;
            cout << "\nВведите значение для вставки: "; cin >> value;
            cout << "\nВведите индекс для вставки: "; cin >> index;
            stl.insertAt(value, index);
        }
        else if (answer == 9) {
            if (stl.isEmpty()) cout << "Пусто!";
            else cout << "список не пуст";
        }
        else if (answer == 10) { break; }
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}

template <class T>
void workWithStackPtr (List<T>& stl) {
    int answer = 0;
    while (answer != 10) {
        cout << "\n1. Добавить элемент в конец"
                "\n2. Удалить элемент с конца"
                "\n3. Очистить"
                "\n4. Просмотреть список"
                "\n5. Добавить элемент в голову"
                "\n6. Удалить элемент с головы"
                "\n7. Удалить по индексу"
                "\n8. Добавить по индексу"
                "\n9. Проверить на пустоту"
                "\n10. Выйти" << endl;
        cout << "> "; cin >> answer;
        if (answer == 1) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            stl.pushBack(value);
        }
        else if (answer == 2) stl.popBack();
        else if (answer == 3) stl.clear();
        else if (answer == 4) stl.print();
        else if (answer == 5) {
            T value;
            cout << "\nВведите элемент: "; cin >> value;
            stl.pushHead(value);
        }
        else if (answer == 6) stl.popFront();
        else if (answer == 7) {
            int value;
            cout << "\nВведите индекс: "; cin >> value;
            stl.removeAt(value);
        }
        else if (answer == 8) {
            int index;
            T value;
            cout << "\nВведите значение для вставки: "; cin >> value;
            cout << "\nВведите индекс для вставки: "; cin >> index;
            stl.insert(value, index);
        }
        else if (answer == 9) {
            if (stl.isEmpty()) cout << "Пусто!";
            else cout << "стек не пуст";
        }
        else if (answer == 10) { break; }
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}

void start() {
    bool works = true;
    while(works) {
        cout <<
             "\nВыберете способ представления стека"
             "\n\t1. Цепной"
             "\n\t2. Сплеш"
             "\n\t3. Выйти" << endl;
        int answer; cout << "> "; cin >> answer;
        if (answer == 1 || answer == 2) {
            if (answer == 1) {
                List<int> sl;
                workWithStackPtr(sl);
            } else if (answer == 2) {
                int size;
                std::cout << "Введите размер списка: "; std::cin >> size;
                SplashList<int> sl(size);
                workSplash(sl);
            }
        }
        else if (answer == 3) works = false;
        else cout << "\n-----Такого пункта нет!-----\n";
    }
}


int main() {
    start();
}
