#include <iostream>
#include "Node.h"
#include "Queues.h"

/**
 * Добавляет новый узел с данными в конец очереди.
 *
 * Создает новый узел с переданными данными и добавляет его в конец очереди.
 * Если очередь пуста, новый узел становится одновременно и началом, и концом очереди.
 * Иначе новый узел добавляется после текущего последнего элемента.
 *
 * @param data Целочисленное значение для добавления в очередь
 * @param node_head Ссылка на указатель начала очереди (может быть nullptr для пустой очереди)
 * @param node_tail Ссылка на указатель конца очереди (может быть nullptr для пустой очереди)
 * @post Создан новый узел с данными data
 * @post Если очередь была пуста: node_head и node_tail указывают на новый узел
 * @post Если очередь не пуста: node_tail->next указывает на новый узел, node_tail обновлен
 * @throws std::bad_alloc Если не удается выделить память для нового узла
 * @note Функция переписана для устранения дублирования кода по сравнению с закомментированной версией
 */
// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.
void Queues::add_nodes(int data, PNode& node_head, PNode& node_tail)
{
	// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
	// FIX_ME: Название должно быть осмысленным.
	// FIX_ME: Функция переписана для устранения дублирования кода.
	// Узел создаётся один раз (new_node) и затем либо становится головой очереди,
	// либо добавляется в её конец.
	/*PNode Temp;
	if (Head == NULL)
	{
		Head = new Node;
		Tail = Head;
		Head->next = NULL;

	}
	else
	{
		Temp = new Node;
		Tail->next = Temp;
		Tail = Temp;
		Tail->next = NULL;
	}
	Tail->data = data;*/

	PNode new_node = new Node;
	new_node->data = data;
	new_node->next = nullptr;

	if (node_head == nullptr) {
		node_head = new_node;
		node_tail = new_node;
	}
	else {
		node_tail->next = new_node;
		node_tail = new_node;
	}

}

/**
 * Отображает исходное состояние очереди: элементы и адреса начала и конца.
 *
 * Выводит на экран все элементы очереди в порядке от начала к концу,
 * а также адреса первого и последнего элементов с их значениями.
 *
 * @param node_head Указатель на начало очереди
 * @note Если очередь пуста, поведение не определено (предполагается непустая очередь)
 * @warning Метод предполагает, что очередь не пуста (согласно условию задачи)
 */
void Queues::show_source(PNode node_head) {
	// FIX_ME: Название должно быть осмысленным.
	PNode temporary = node_head;

	std::cout << std::endl << "Исходная очередь: ";
	while (temporary != nullptr) {
		std::cout << temporary->data << " ";
		temporary = temporary->next;
	}

	PNode last_node = node_head;
	while (last_node->next != nullptr) {
		last_node = last_node->next;
	}
	std::cout << std::endl << "Исходный адрес первого элемента: " << node_head << " " << node_head->data << std::endl;
	std::cout << std::endl << "Исходный адрес последнего элемента: " << last_node << " " << last_node->data << std::endl;
}


/**
 * Удаляет указанное количество элементов из начала очереди.
 *
 * Последовательно удаляет amount_to_delete элементов из начала очереди,
 * освобождая занимаемую ими память. После удаления указатель node_head
 * обновляется и указывает на новый первый элемент очереди.
 *
 * @param amount_to_delete Количество элементов для удаления (должно быть > 0)
 * @param node_head Ссылка на указатель начала очереди
 * @pre amount_to_delete должно быть меньше или равно размеру очереди
 * @pre Очередь не должна быть пустой
 * @post Из очереди удалено amount_to_delete первых элементов
 * @post node_head указывает на новый первый элемент (или nullptr, если удалены все)
 * @warning Если amount_to_delete превышает размер очереди, поведение не определено
 */
// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
// FIX_ME: Название должно быть осмысленным.
void Queues::delete_nodes(int amount_to_delete, PNode& node_head)
{
	// FIX_ME: Название должно быть осмысленным.
	PNode temporary;
	for (int i = 0; i < amount_to_delete; i++) {
		temporary = node_head;
//		std::cout << temporary->data << " " << temporary->next << " ";
		node_head = node_head->next;
		delete temporary;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/**
 * Отображает состояние очереди после удаления элементов.
 *
 * Выводит новый первый элемент очереди с его адресом, все оставшиеся элементы,
 * а также новый последний элемент с его адресом. Если после удаления очередь
 * стала пустой, выводится соответствующее сообщение и нулевые адреса.
 *
 * @param node_head Указатель на начало очереди (может быть nullptr для пустой очереди)
 * @note Метод корректно обрабатывает случай полностью удаленной очереди
 */
void Queues::show_fixed(PNode node_head)
{
	// FIX_ME: Название должно быть осмысленным.
	PNode temporary1 = nullptr;
	PNode temporary2 = node_head;
	if (node_head == nullptr) {
		std::cout << "Очередь после удаления элементов оказалась пустой" << std::endl;
		//int* ptr = nullptr;
		// FIX_ME: Название должно быть осмысленным
		int* null_address = nullptr;
		std::cout << "Начало очереди: " << null_address << std::endl;
		std::cout << "Конец очереди: " << null_address << std::endl;
	}
	else {
		std::cout << "Новое начало очереди: " << temporary2 << " " << temporary2->data << std::endl;
		std::cout << "Оставшиеся элементы очереди: ";
		while (node_head != nullptr) {
			temporary1 = node_head;
			std::cout << temporary1->data << " ";
			node_head = node_head->next;
			//delete temp;
		}
		std::cout << std::endl << "Новый конец очереди: " << temporary1 << " " << temporary1->data << std::endl;
	}
}
