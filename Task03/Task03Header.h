#pragma once

#include "Node.h"
#include "ListInitialization.h"

/**
 * Класс Lists управляет пользовательским интерфейсом и основной логикой программы.
 *
 * Разделение логики на класс Lists (взаимодействие с пользователем)
 * и класс LinearList (работа со списком) следует принципу единственной ответственности.
 * Lists отвечает только за ввод/вывод и последовательность операций,
 * делегируя манипуляции с данными классу LinearList.
 */
class Lists {
private:
	void fill_lists(int amount_of_elements, PNode& head_original_list, PNode& tail_original_list,
		PNode& head_copy_list, PNode& tail_copy_list, LinearList& list);
	int fill_input_number(PNode& head_copy_list, LinearList& list);
	int fill_element();
	void delete_elements(PNode& head_copy_list, LinearList& list, int amount_of_elements);
public:
	void show_work();
};