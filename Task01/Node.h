#pragma once


/**
 * Узел односвязного списка.
 *
 * Содержит данные (value) и указатель на следующий узел (next).
 * Использование класса с публичными полями оправдано, так как Node
 * является простой структурой данных без инвариантов, требующих защиты.
 */
// FIX_ME: по условию тип не Node, а TNode 
//class Node
class TNode {
public:
    // FIX_ME: в Google Codestyle Guide названия переменных должны быть осмысленными  
    //int x;          // Значение узла
    int value;
    //Node* next;     // Указатель на следующий узел
    TNode* next;     // Указатель на следующий узел

    // Node(int d) : x(d), next(nullptr) {}

    TNode(int input_data) : value(input_data), next(nullptr) {

    }
};