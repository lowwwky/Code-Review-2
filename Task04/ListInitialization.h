#pragma once

#include <iostream>

#include "Node.h"


/**
 * Класс для работы с двусвязным линейным списком.
 *
 * Предоставляет функциональность для создания и управления двусвязным списком,
 * включая добавление элементов, удаление, отображение, запись в файл
 * в обратном порядке и полную очистку списка.
 *
 * @note Все методы класса работают с целочисленными значениями (int)
 * @see Node структура для представления узла списка
 */
// FIX_ME: Название должно быть осмысленным.
// Класс для работы с двусвязным списком
class List {
private:
    //Uzel* Perviy; // Указатель на первый узел
    Node* first_node;

public:
    // Инициализация списка
    void initialization();

    // Добавление элемента в конец списка
    void add_element(int input_value);

    // Удаление указанного узла
    void delete_element(Node* node_to_delete);

    // Вывод списка на экран
    void show_elements() const;

    // Запись в файл в обратном порядке и удаление элементов
   // void write_to_file(const std::string& file_name);
    bool write_to_file(const std::string& file_name);

    // Очистка всего списка
    void clear_list();
};
