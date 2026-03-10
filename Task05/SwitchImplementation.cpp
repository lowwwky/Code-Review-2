#include <iostream>
#include <fstream>

#include "Switch.h"
#include "../../Lab2Task03/Lab2Task03/Errors.h"

// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.


/**
 * Заполняет список указанным пользователем способом.
 *
 * Предоставляет интерактивный выбор метода заполнения контейнера:
 * 1. Ручной ввод с клавиатуры - каждый элемент вводится пользователем
 * 2. Генерация случайных чисел - для быстрого создания тестовых данных
 * 3. Чтение из текстового файла - для повторного использования данных
 *
 * При ручном вводе выполняется валидация каждого числа с использованием
 * класса CheckInput для обеспечения корректности вводимых данных.
 * При файловом вводе проверяется успешность открытия файла.
 *
 * @param input_list Список для заполнения (передаётся по ссылке)
 * @param amount_of_elements Количество элементов для добавления
 */
// FIX_ME: Название должно быть осмысленным.
//void input_data(list<int>& input_list, int amount_of_elements)//Заполнение списков
//{
void SwitchDigits::input_data(std::list<int>&input_list, int amount_of_elements) {
    // FIX_ME: Сам способ заполнения не объявлен. Лучше переформулировать предложение.
    // FIX_ME: Название должно быть осмысленным.
    //int m, element_data;
    //cout << "Выберете способ заполнения контейнера: " << endl;
    //cout << "1)Ввод с клавиатуры." << endl;
    //cout << "2)Ввод с помощью рандомайзера." << endl;
    //cout << "3)Ввод данных из текстового файла." << endl;
    //cin >> m;

    int filling_type, element_data;
    std::string temporary_filling_type, temporary_number;
    CheckInput errors;
    std::cout << "Доступные способы заполнения контейнера: " << std::endl
        << "1) Вывод с клавиатуры" << std::endl
        << "2) Ввод с помощью рандомайзера" << std::endl
        << "3) Ввод данных из текстового файла" << std::endl;
    while (true) {
        std::cout << "Введите способ заполнения(1,2,3): ";
        std::getline(std::cin, temporary_filling_type);
        if (errors.is_valid_number(temporary_filling_type)) {
            break;
        }
        std::cout << "Ошибка. Введено неверное значение." << std::endl;
    }
    filling_type = errors.string_to_int(temporary_filling_type);

    //switch (m)
    switch (filling_type) {
        //{
        case 1: {
        //{
            for (int i = 0; i < amount_of_elements; i++) {
            //{
                while (true) {
                    std::cout << "Введите " << i + 1 << " целое число: ";
                    //std::cin >> element_data;
                    std::getline(std::cin, temporary_number);
                    if (errors.is_valid_number(temporary_number)) {
                        break;
                    }
                    else {
                        std::cout << "Ошибка. Введено неверное значение. " << std::endl;
                    }
                }
                element_data = errors.string_to_int(temporary_number);
                input_list.insert(input_list.end(), element_data);
            }
            break;
        }
        case 2: {
        //{
            srand(time(0));
            for (int i = 0; i < amount_of_elements; i++)
                input_list.insert(input_list.end(), rand() % 101 - 50);
            break;
        }
        case 3: {
        //{
            //ifstream file("a.txt", ios::in); // a.txt { 27 -8 -11 -25 33 47 -30 -41 -8 3 -13 -29 -38 -18}
            std::ifstream file("input.txt", std::ios::in);
            if (!file) {
            //{
                std::cout << "Ошибка. Файл не был открыт.";
                return;
            }
            for (int i = 0; i < amount_of_elements; i++) {
            // {
                file >> element_data;
                input_list.insert(input_list.end(), element_data);
            }
            file.close();
            break;
        }
        default: {
        //{
            std::cout << "Ошибка ввода." << std::endl;
            break;
        }
    }
}

/**
 * Выводит содержимое списка в консоль.
 *
 * Последовательно перебирает все элементы списка от начала до конца
 * и выводит их через пробел. После завершения вывода переводит строку.
 * Функция не модифицирует список (const-квалификатор).
 *
 * @param list_to_print Константный список для вывода
 */
// FIX_ME: Название должно быть осмысленным.
//void print_data(const list<int> input_list)//Вывод содержимого списков
//{
void SwitchDigits::print_data(const std::list<int> list_to_print) {
    for (auto it = list_to_print.begin(); it != list_to_print.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/**
 * Переносит средний элемент первого списка в конец второго списка.
 *
 * Реализует условие задания: "Помещает средний элемент списка L1 в конец списка L2".
 * Средний элемент определяется как элемент с индексом size/2 (целочисленное деление).
 * Для переноса используется встроенный метод splice(), который перемещает элемент
 * без копирования и удаления, сохраняя целостность обоих списков.
 *
 * Алгоритм работы:
 * 1. Итератор устанавливается на начало первого списка
 * 2. Перемещается на size/2 позиций вперёд (к среднему элементу)
 * 3. Метод splice переносит элемент из первого списка в конец второго
 *
 * @param List1 Исходный список, из которого забирается средний элемент
 * @param List2 Целевой список, в конец которого добавляется элемент
 */
// FIX_ME: Название должно быть осмысленным.
//void splice_data(list <int>& List1, list <int>& List2)//Помещает средний элемент списка L1 в конец списка L2
//{
void SwitchDigits::splice_data(std::list <int>& List1, std::list <int>& List2) {
    std::list <int> ::iterator it;
    it = List1.begin();
    auto size = List1.size();
    for (int i = 0; i < size / 2; i++)
        ++it;
    List2.splice(List2.end(), List1, it);
}