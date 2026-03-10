/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны списки list1 и list2; список list1 имеет нечетное количество элементов.
Переместить средний элемент списка list1 в конец списка L2. Использовать один вызов
функции-члена splice.

*/


#include <ctime>
#include <list>
#include <fstream>
#include <iostream>

#include "Switch.h"
#include "../../Lab2Task03/Lab2Task03/Errors.h"
#include "Task05Header.h"

// FIX_ME: В Google Codestyle Guide использование пространство имён std нежелательно.
//using namespace std;

//void input_data(list<int>& L, int n)//Заполнение списков
//{
//    int m, element_data;
//    cout << "Выберете способ заполнения контейнера: " << endl;
//    cout << "1)Ввод с клавиатуры." << endl;
//    cout << "2)Ввод с помощью рандомайзера." << endl;
//    cout << "3)Ввод данных из текстового файла." << endl;
//    cin >> m;
//    switch (m)
//    {
//    case 1:
//    {
//        for (int i = 0; i < n; i++)
//        {
//            cout << "Введите " << i + 1 << " элемент: ";
//            cin >> element_data;
//            L.insert(L.end(), element_data);
//        }
//        break;
//    }
//    case 2:
//    {
//        srand(time(0));
//        for (int i = 0; i < n; i++)
//            L.insert(L.end(), rand() % 101 - 50);
//        break;
//    }
//    case 3:
//    {
//        //ifstream file("a.txt", ios::in); // a.txt { 27 -8 -11 -25 33 47 -30 -41 -8 3 -13 -29 -38 -18}
//        ifstream file("input.txt", ios::in);
//        if (!file)
//        {
//            cout << "Ошибка. Файл не был открыт.";
//            return;
//        }
//        for (int i = 0; i < n; i++)
//        {
//            file >> element_data;
//            L.insert(L.end(), element_data);
//        }
//        file.close();
//        break;
//    }
//    default:
//    {
//        cout << "Ошибка ввода." << endl;
//        break;
//    }
//    }
//}
//void print_data(const list<int> L)//Вывод содержимого списков
//{
//    for (auto it = L.begin(); it != L.end(); it++)
//        cout << *it << " ";
//    cout << endl;
//}
//void splice_data(list <int>& list1, list <int>& list2)//Помещает средний элемент списка L1 в конец списка L2
//{
//    list <int> ::iterator it;
//    it = list1.begin();
//    auto size = list1.size();
//    for (int i = 0; i < size / 2; i++)
//        ++it;
//    list2.splice(list2.end(), list1, it);
//}

/**
 * Запрашивает у пользователя количество элементов для первого списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int Lists::fill_input_list1() {
    int amount_of_elements = 0;
    CheckInput errors;
    std::string temprorary_amount;
    while (true) {
        std::cout << "Введите положительное НЕЧЁТНОЕ целое число - количество элементов в первом списке: ";
        std::getline(std::cin, temprorary_amount);
        if (errors.is_valid_number(temprorary_amount)) {
            amount_of_elements = errors.string_to_int(temprorary_amount);
            if (amount_of_elements <= 0 || amount_of_elements % 2 != 1) {
                std::cout << "Ошибка: введено неверное значение.\n";
            }
            else {
                break;
            }
        }
        else {
            std::cout << "Ошибка ввода. Попробуйте ещё раз.\n";
        }

    }
    return amount_of_elements;
}

/**
 * Запрашивает у пользователя количество элементов для второго списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int Lists::fill_input_list2() {
    int amount_of_elements = 0;
    CheckInput errors;
    std::string temprorary_amount;
    while (true) {
        std::cout << "Введите положительное целое число - количество элементов во втором списке: ";
        std::getline(std::cin, temprorary_amount);
        if (errors.is_valid_number(temprorary_amount)) {
            amount_of_elements = errors.string_to_int(temprorary_amount);
            if (amount_of_elements < 0) {
                std::cout << "Ошибка: число должно быть больше 0.\n";
            }
            else {
                break;
            }
        }
        else {
            std::cout << "Ошибка ввода. Попробуйте ещё раз.\n";
        }

    }
    return amount_of_elements;
}

/**
 * Демонстрирует работу программы согласно условию лабораторной работы.
 *
 * Реализует основной алгоритм обработки двух списков:
 * 1. Запрашивает размерности списков с проверкой корректности (первый список
 *    должен быть нечётного размера, второй - неотрицательного)
 * 2. Заполняет списки выбранным пользователем способом
 * 3. Выводит исходное содержимое обоих списков
 * 4. Выполняет перенос среднего элемента первого списка в конец второго
 * 5. Выводит изменённое содержимое списков для демонстрации результата
 *
 * @note Метод не возвращает значение, так как вся работа происходит
 *       с локальными списками, а результат выводится на экран.
 */
//int main()
//{
void Lists::show_work() {

    //setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "Russian.utf8");

    SwitchDigits switch_digits;

    // FIX_ME: Название должно быть осмысленным.
    /*int amount_items_first_list, amount_items_second_list;
    list <int> list1;
    list <int> list2;*/

    //cout << "Введите размерность списка n1 (n1 - нечётное): ";
    //cin >> amount_items_first_list;
    //input_data(list1, amount_items_first_list);
    // 
    //cout << "Введите размерность списка n2 (n2 >= 0): ";
    //cin >> amount_items_second_list;
    // 
    // FIX_ME: При ошибке ничего не происходит. Лучше выносить все проверки в отдельный файл и проверять сразу же при вводе.
    //if (amount_items_first_list < 0 || amount_items_second_list < 0 || amount_items_first_list % 2 != 1)
    //{
    //    cout << "Ошибка. Недопустимый размер списка.";
    //    return 1;
    //}

    int amount_items_first_list, amount_items_second_list;
    std::list <int> list1;
    std::list <int> list2;

    amount_items_first_list = fill_input_list1();
    switch_digits.input_data(list1, amount_items_first_list);
    amount_items_second_list = fill_input_list2();

    //input_data(list2, amount_items_second_list);
    switch_digits.input_data(list2, amount_items_second_list);

    std::cout << "Изначальное содержимое списков." << std::endl;

    std::cout << "Список L1: ";
    //print_data(list1);
    switch_digits.print_data(list1);

    std::cout << "Список L2: ";
    //print_data(list2);
    switch_digits.print_data(list2);

    //splice_data(list1, list2);
    switch_digits.splice_data(list1, list2);

    std::cout << "Изменённое содержание списков." << std::endl;
    std::cout << "Список L1: ";
   // print_data(list1);
    switch_digits.print_data(list1);

    std:: cout << "Список L2: ";
    //print_data(list2);
    switch_digits.print_data(list2);

    //return 0;
}