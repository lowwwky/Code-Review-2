#pragma once

#include "Node.h"


/**
 * Класс, реализующий структуру данных "Стек" на основе односвязного списка.
 *
 * Стек работает по принципу LIFO (Last In - First Out) - последним пришёл,
 * первым ушёл. Элементы добавляются и удаляются только с вершины стека.
 * Каждый элемент стека представлен узлом TNode, содержащим данные и указатель
 * на следующий элемент.
 */
// FIX_ME: Реализацию лучше писать в отдельном файле.
// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.
// FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores
class Stack {
private:
    TNode* top; // Указатель на вершину стека

public:
    Stack() : top(nullptr) {}

    void push(int node_data);
    void show() const;
    void delete_data(Stack& stack_to_delete);
    void show_address() const;
    int get_top_value() const;
    bool is_empty() const;

    //FIX_ME: Название переменных должно быть информативным
    /*void push(int d)
    {
        TNode* newNode = new TNode(d); // Создаем новый узел
        newNode->next = top; // Новый узел указывает на старую вершину
        top = newNode; // Новый узел становится вершиной стека
    }*/

    /*void show() const
    {
        TNode* current = top;
        while (current != nullptr)
        {
            //cout << current->x << " ";
            std::cout << current->x << " ";
            current = current->next;
        }
        //cout << endl;
        std::cout << std::endl;
    }*/

    
    /*void showAddress() const
    {
        //cout << "Адрес вершины стека: " << top << endl;
        std::cout << "Адрес вершины стека: " << top << std::endl;
    }*/

    /*int getTopValue() const
    {
        if (top != nullptr)
        {
            return top->x;
        }
        return 1;
    }*/

    /*bool isEmpty() const
    {
        return top == nullptr;
    }*/
};