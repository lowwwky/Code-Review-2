# include <iostream>
# include "Node.h"
# include "ListInitialization.h"

// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.
// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores
//void add(int data, PNode& Head, PNode& LastNode)
//{

/**
 * Добавляет новый элемент в конец списка.
 *
 * Использование указателя на последний элемент (last_node) позволяет
 * добавлять элементы за O(1) вместо O(n), что особенно важно при построении
 * списка из большого количества элементов. При добавлении первого элемента
 * обновляются оба указателя (head и last_node).
 *
 * @param data Значение для добавления
 * @param head Голова списка (обновляется при добавлении первого элемента)
 * @param last_node Хвост списка (обновляется при каждом добавлении)
 */
void LinearList::add(int data, PNode& head, PNode& last_node) {
	// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
	// FIX_ME: Название должно быть осмысленным.
	//PNode Temp;
	PNode temporary;

	if (head == nullptr) {
	// {
		head = new Node;
		last_node = head;
		head->next = nullptr;
	} else {
	//{
		// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores
		temporary = new Node;
		last_node->next = temporary;
		last_node = temporary;
		last_node->next = nullptr;
	}
	last_node->value = data;
}

//PNode find(int data, PNode& Head)
//{

/**
 * Находит позицию для вставки нового элемента в упорядоченный список.
 *
 * @param data Значение для вставки
 * @param head Голова списка
 * @return Указатель на узел, после которого нужно вставить новый элемент
 */
PNode LinearList::find(int data, PNode & head) {
		// FIX_ME: в Google Codestyle Guide названия перменных должны быть в виде lower_case_with_underscores
		//PNode Temp = Head;
		//PNode prev = Head;
		PNode temp = head;
		PNode prev = head;

		//while (Temp != nullptr && Temp->value < data) 
		//{
		while (temp != nullptr && temp->value < data) {
			//prev = Temp;
			//Temp = Temp->next;
			prev = temp;
			temp = temp->next;
		}

		return prev;
	}

//void newadd(int data, PNode p, PNode& Head)
//{
/**
 * Вставляет новый элемент в упорядоченный список с сохранением возрастания.
 *
 * Основная операция по условию задачи. Использует find() для определения
 * правильной позиции вставки. Особый случай - вставка в начало списка,
 * когда новый элемент меньше или равен первому элементу.
 *
 * @param data Значение для вставки
 * @param pnode Позиция для вставки (результат find)
 * @param head Голова списка (обновляется при вставке в начало)
 */
void LinearList::new_add(int data, PNode pnode, PNode& head) {
	PNode newNode = new Node;
	newNode->next = nullptr;
	newNode->value = data;

	// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores
	//if (Head == nullptr || Head->value >= data) 	
	//{
	if (head == nullptr || head-> value >= data) {
		//newNode->next = Head;
		//Head = newNode;
		newNode->next = head;
		head = newNode;
	} else {
	//{
		// FIX_ME: в Google Codestyle Guide названия перменных должны быть в виде lower_case_with_underscores
		//PNode Prev = find(data, Head);
		//if (Prev != nullptr) {
		//{
		PNode prev = find(data, head);
		if (prev != nullptr) {
			//newNode->next = Prev->next;
			//Prev->next = newNode;
			newNode->next = prev->next;
			prev->next = newNode;
		}
	}
}

//void show(PNode& Head) 
//{
/**
 * Отображает элементы списка с поясняющим текстом.
 * @param head Голова списка
 */
void LinearList::show(PNode& head) {
	// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
	// FIX_ME: Название должно быть осмысленным.
	//PNode Mynode = Head;
	//PNode Temp = nullptr;

	PNode input_node = head;
	PNode temporary = nullptr;
	int count = 0;
	//cout << "Все полученные числа: ";
	std::cout << "Полученные числа: ";

	while (input_node != nullptr)
	{
		//cout << input_node->x << " ";
		std::cout << input_node->value << " ";
		input_node = input_node->next;
	}
	//cout << endl;
	std::cout << std::endl;

}

//void show2(PNode& Head) {
// {
/**
 * Отображает элементы списка с улучшенным форматированием.
 *
 * Альтернативный метод вывода для случаев, когда нужно
 * обработать пустой список особым образом. Проверка пустоты выполняется
 * до цикла вывода для корректного сообщения.
 *
 * @param head Голова списка
 */
void LinearList::show_new_list(PNode& head) {
	// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
	// FIX_ME: Название должно быть осмысленным.
	//PNode Mynode = Head;
	//PNode Temp = nullptr;
	PNode input_node = head;
	//PNode Temp = nullptr;

	int count = 0;
	//cout << "Все полученные числа: ";

	if (input_node == nullptr) {
		//{
		//cout << "Пусто!";
		std::cout << "Пусто.";
	}

	while (input_node != nullptr) {
		//{
		//cout << input_node->x << " ";
		std::cout << input_node->value << " ";
		input_node = input_node->next;
	}
	// FIX_ME: "Пусто" выводится всегда.
	//if (input_node == nullptr) {
	//	//{
	//	//cout << "Пусто!";
	//	std::cout << "Пусто.";
	//}
	//cout << endl;
	std::cout << std::endl;
}

//PNode Find(PNode Head, int data) {
//{
/**
 * Находит узел с заданным значением.
 *
 * Поиск по значению необходим для проверки существования элемента
 * перед удалением. В отличие от find(), возвращает сам найденный узел,
 * а не предыдущий, что удобно для операций с уже найденным элементом.
 *
 * @param head Голова списка
 * @param data Искомое значение
 * @return Указатель на найденный узел или nullptr
 */
PNode LinearList::find_node(PNode head, int data){
	//PNode q = Head;
	PNode current_node = head;
	while (current_node && current_node->value != data)
		current_node = current_node->next;
	return current_node;
}

// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.
//void DeleteNode(PNode& Head, PNode OldNode) {
// {

/**
 * Удаляет указанный узел из списка.
 *
 * Принимает указатель на удаляемый узел, чтобы избежать повторного
 * поиска. Особый случай - удаление первого элемента, когда обновляется голова.
 * Обязательная проверка на пустоту списка предотвращает ошибки.
 *
 * @param head Голова списка (обновляется при удалении первого элемента)
 * @param old_node Удаляемый узел
 */
void LinearList::delete_node(PNode& head, PNode old_node) {
	// FIX_ME: Название должно быть осмысленным.
	//PNode q = head;

	if (head == nullptr) {
		std::cout << "Cписок пуст." << std::endl;
	}

	PNode current_node = head;

	if (head == old_node) {
		head = old_node->next;				 // удаляем первый элемент.
	}
	else {
	// {
		while (current_node->next != old_node)			// ищем элемент, если оне не первый.
			current_node = current_node->next;
		current_node->next = old_node->next;
	}
	delete old_node;
}