#pragma once

// FIX_ME: Название должно быть осмысленным.
// Структура узла двусвязного списка
//struct Uzel {
struct Node {
    // FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
    // FIX_ME: Название должно быть осмысленным.
    //int Dannye;         // Данные узла
    //Node* Predydushiy;  // Указатель на предыдущий узел
    //Node* Sleduyushiy;  // Указатель на следующий узел

    int value;         // данные узла
    Node* previous_node;  // указатель на предыдущий узел
    Node* next_node;  // указатель на следующий узел
};