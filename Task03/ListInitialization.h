#pragma once

/**
 * Класс LinearList реализует односвязный линейный список и операции над ним.
 *
 * Инкапсуляция структуры данных и операций над ней в отдельный класс
 * позволяет скрыть детали реализации и предоставить чистый интерфейс для работы со списком.
 * Все методы следуют принципу единственной ответственности.
 */
class LinearList {
public:
	void add(int data, PNode& Head, PNode& LastNode);
	PNode find(int data, PNode& Head);

	// FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores
	void new_add(int data, PNode p, PNode& Head);

	void show(PNode& Head);

	// FIX_ME: Название должно быть осмысленным.
	//void show2(PNode& Head);
	void show_new_list(PNode& head);

	// FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores
	//PNode find(PNode Head, int data);
	PNode find_node(PNode head, int data);

	// FIX_ME: в Google Codestyle Guide названия методов пишутся как lower_case_with_underscores
	//void DeletNode(PNode& Head, PNode OldNode);
	void delete_node(PNode& head, PNode old_node);
};