#include <iostream>
#include <fstream>

#include "ListInitialization.h"

/**
 * Инициализирует пустой список.
 *
 * Устанавливает указатель на первый элемент списка в nullptr,
 * что соответствует пустому списку. Данный метод следует вызывать
 * после создания объекта списка перед началом работы с ним.
 *
 * @post first_node == nullptr (список пуст)
 */
void List::initialization() {
    first_node = nullptr;
}


/**
 * Добавляет новый элемент в конец двусвязного списка.
 *
 * Создает новый узел с указанным значением и добавляет его в конец списка.
 * Если список пуст, новый узел становится первым элементом.
 * Иначе происходит обход списка до последнего элемента и добавление
 * нового узла после него с соответствующей настройкой связей.
 *
 * @param input_value Целочисленное значение для добавления в список
 * @post Список содержит новый элемент в конце, размер списка увеличивается на 1
 * @throws std::bad_alloc Если не удается выделить память для нового узла
 * @note Работает за O(n), где n - текущий размер списка
 */
void List::add_element(int input_value) {
    Node* newNode = new Node;
    newNode->value = input_value;
    newNode->previous_node = nullptr;
    newNode->next_node = nullptr;

    if (first_node == nullptr) {
        first_node = newNode;
    }
    else {
        Node* current_node = first_node;
        while (current_node->next_node != nullptr) {
            current_node = current_node->next_node;
        }
        current_node->next_node = newNode;
        newNode->previous_node = current_node;
    }
}

/**
 * Удаляет указанный узел из двусвязного списка.
 *
 * Удаляет переданный узел из списка, корректно перенастраивая связи
 * между соседними узлами. При удалении первого узла обновляется
 * указатель first_node. При удалении последнего узла соответствующим
 * образом обновляются связи.
 *
 * @param node_to_delete Указатель на удаляемый узел
 * @pre Указатель node_to_delete должен быть валидным (можно проверить на nullptr)
 * @post Указанный узел удален из списка, память освобождена
 * @warning Если передан некорректный указатель (не принадлежащий списку),
 *          поведение не определено
 */
void List::delete_element(Node* node_to_delete) {
    if (node_to_delete == nullptr) return;

    Node* previous = node_to_delete->previous_node;
    Node* next = node_to_delete->next_node;

    if (previous != nullptr) {
        previous->next_node = next;
    }
    else {
        first_node = next;
    }

    if (next != nullptr) {
        next->previous_node = previous;
    }

    delete node_to_delete;
}


/**
 * Выводит все элементы списка на экран.
 *
 * Выполняет последовательный обход списка от первого элемента к последнему,
 * выводя значения всех элементов через пробел. После вывода всех
 * элементов осуществляется переход на новую строку.
 *
 * @note Метод не изменяет состояние списка
 * @note Если список пуст, выводится только "Список: " и пустая строка
 */
void List::show_elements() const {
    Node* current = first_node;
    std::cout << "Список: ";
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next_node;
    }
    std::cout << std::endl;
}

/**
 * Записывает элементы списка в файл в обратном порядке с последующим удалением.
 *
 * Выполняет обход списка от последнего элемента к первому, записывая
 * значения в файл. Элементы разделяются ровно одним пробелом.
 * В процессе записи каждый элемент удаляется из списка.
 *
 * @param file_name Имя файла для записи (может включать путь)
 * @return true - если файл успешно открыт и данные записаны,
 *         false - если не удалось открыть файл для записи
 * @post Список становится пустым, все элементы удалены
 * @note Файл открывается в режиме trunc (перезапись существующего содержимого)
 * @warning В случае ошибки открытия файла список НЕ изменяется
 */
//void List::write_to_file(const std::string& file_name) {
bool List::write_to_file(const std::string& file_name) {
    std::ofstream file(file_name, std::ios::out | std::ios::trunc);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        //return;
        return false;
    }

    bool first_element = true;
    Node* current_node = first_node;

    // Находим последний элемент
    while (current_node != nullptr && current_node->next_node != nullptr) {
        current_node = current_node->next_node;
    }

    // Записываем и удаляем элементы с конца
    while (current_node != nullptr) {
        if (first_element) {
            file << current_node->value;
            first_element = false;
        }
        else {
            file << " " << current_node->value;
        }

        Node* previous = current_node->previous_node;
        delete_element(current_node);
        current_node = previous;
    }

    file.close();
    //std::cout << "Данные записаны в файл и список очищен." << std::endl;
    return true;

}


/**
 * Полностью очищает список, удаляя все элементы и освобождая память.
 *
 * Последовательно проходит по всем элементам списка от первого к последнему,
 * удаляя каждый узел и освобождая занимаемую им память.
 * После завершения список становится пустым.
 *
 * @post first_node == nullptr, все узлы удалены
 * @note Работает за O(n), где n - размер списка
 */
void List::clear_list() {
    Node* current_node = first_node;
    while (current_node != nullptr) {
        Node* next = current_node->next_node;
        delete current_node;
        current_node = next;
    }
    first_node = nullptr;
}