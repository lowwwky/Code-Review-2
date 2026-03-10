#pragma once

#include "Node.h"

/**
 * Класс для работы с очередью (queue) на основе односвязного списка.
 *
 * Реализует структуру данных "очередь", где элементы добавляются в конец
 * и удаляются из начала. Класс предоставляет методы для добавления элементов,
 * отображения состояния очереди, удаления элементов из начала и
 * демонстрации результатов операций.
 * @note Все методы работают с целочисленными значениями (int)
 * @see PNode тип-псевдоним для указателя на узел (Node*)
 */
class Queues {
public:
	// FIX_ME: в Google Codestyle Guide названия переменных, методов пишутся как lower_case_with_underscores.
	// void add(int data, PNode& Head, PNode& Tail);
	// void show1(PNode head);
	// void del(int m, PNode& Head);
	// void show2(PNode head);
	
	void add_nodes(int data, PNode& node_head, PNode& node_tail);
	void show_source(PNode node_head);
	void delete_nodes(int amount_to_delete, PNode& node_head);
	void show_fixed(PNode node_head);
};