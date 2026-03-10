/*Дан односвязный линейный список и указатель на голову списка P1. Значения
элементов списка упорядочены по возрастанию. Необходимо создать копию исходного списка,
после чего во вновь созданном списке вставить в список значение M так, чтобы он остался
упорядоченным и вывести ссылку на первый элемент полученного списка P2


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/
//#include <windows.h>
#include <iostream>
#include <limits>
#include <string>

#include "Errors.h"
#include "Node.h"
#include "ListInitialization.h"
#include "Task03Header.h"

// FIX_ME: В Google Codestyle Guide использование пространство имён std нежелательно.
//using namespace std;

// FIX_ME: Лучше использовать отдельные файлы для разных классов.
/*class Node
{
public:
	int x;
	Node* next;
};
typedef Node* PNode;

void add(int data, PNode& Head, PNode& LastNode)
{
	PNode Temp;
	if (Head == nullptr)
	{
		Head = new Node;
		LastNode = Head;
		Head->next = nullptr;
	}
	else
	{
		Temp = new Node;
		LastNode->next = Temp;
		LastNode = Temp;
		LastNode->next = nullptr;
	}
	LastNode->x = data;
}

PNode find(int data, PNode& Head)
{
	PNode Temp = Head;
	PNode prev = Head;
	while (Temp != nullptr && Temp->x < data)
	{
		prev = Temp;
		Temp = Temp->next;
	}
	return prev;
}

void newadd(int data, PNode p, PNode& Head)
{
	PNode newNode = new Node;
	newNode->next = nullptr;
	newNode->x = data;
	if (Head == nullptr || Head->x >= data)
	{
		newNode->next = Head;
		Head = newNode;
	}
	else
	{
		PNode Prev = find(data, Head);
		if (Prev != nullptr)
		{
			newNode->next = Prev->next;
			Prev->next = newNode;
		}
	}
}

void show(PNode& Head)
{
	PNode Mynode = Head;
	//PNode Temp = nullptr;
	int count = 0;
	cout << "Все полученные числа: ";

	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;
	}
	cout << endl;

}

void show2(PNode& Head)
{
	PNode Mynode = Head;
	//PNode Temp = nullptr;
	int count = 0;
	cout << "Все полученные числа: ";

	while (Mynode != nullptr)
	{
		cout << Mynode->x << " ";
		Mynode = Mynode->next;

	}
	if (Mynode == nullptr)
	{
		cout << "Пусто!";
	}
	cout << endl;

}

PNode Find(PNode Head, int data)
{
	PNode q = Head;
	while (q && q->x != data)
		q = q->next;
	return q;
}


void DeleteNode(PNode& Head, PNode OldNode)
{
	PNode q = Head;
	if (Head == OldNode)
		Head = OldNode->next;				 // удаляем первый элемент.
	else
	{
		while (q->next != OldNode)			// ищем элемент, если оне не первый.
			q = q->next;
		q->next = OldNode->next;
	}
	delete OldNode;
}*/


// FIX_ME: Код лучше разбивать на более мелкие подзадачи.
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	setlocale(LC_ALL, "Russian.utf8");
//	PNode p1 = nullptr;
//	PNode p2 = nullptr;
//	PNode p3 = nullptr;
//	PNode p4 = nullptr;
//	int n, m;
// 
	// FIX_ME: Слишком много деталей.
//	cout << "Добро пожаловать!" << endl;
//	cout << "Перед нами последняя задача: " << endl;
//	cout << "Дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << endl;
//	cout << "Необходимо создать копию исходного списка, после чего во вновь созданном списке вставить" << endl;
//	cout << "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << endl << endl;
//	cout << "----------------------------------------------------------------------" << endl << endl;
//	cout << "Вам необхожимо будет ввести количество элементов в списке," << endl;
//	cout << "а позже ввести значения элементов СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ " << endl;
//	cout << "и ввести число которое вы хотите вставить." << endl;
//	cout << "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ 1 2 3 4 5 6" << endl;
//	cout << "---------------------------------------------------------------------" << endl << endl;
//	cout << "Введите число n - количество элементов в списке: ";
//	cin >> n;
//	cout << endl << "Введите " << n << " чисел в порядке возрастания (!!!!): ";
//	for (int i = 0; i < n; i++)
//	{
//		int j;
//		cin >> j;
//		add(j, p1, p2);
//		add(j, p3, p4);
//	}
//
//	cout << endl << "Введите целое значение числа m, которое необходимо будет вставить: ";
//	cin >> m;
//	show(p1);
//	cout << endl;
//	PNode P = find(m, p3);
//	newadd(m, P, p3);
//	show(p3);
//	int choice;
//	cout << endl << "Хотите удалить какой-нибудь элемент?" << endl;
//	cout << "Если да, то напишите 1" << endl;
//	cout << "Если нет, то напишите 2" << endl;
//	cout << "Ваш выбор: ";
//	cin >> choice;
//	cout << endl;
//	switch (choice)
//	{
//	case 1:
//	{
//		cout << "Введите число - количество элементов которое вы хотите удалить: ";
//		int num;
//		cin >> num;
//		for (int i = 0; i < num; i++)
//		{
//			cout << "Введите значение элемента, который вы хотите удалить: ";
//			int x;
//			cin >> x;
//			PNode p = Find(p3, x);
//			cout << endl;
//			cout << "Удаление...." << endl;
//			DeleteNode(p3, p);
//		}
//		show2(p3);
//		//show(p3);
//	}break;
//
//	case 2:
//	{
//		{
//			cout << "Спасибо за терпение!!!" << endl;
//			cout << "До свидания!!!" << endl;
//		}
//	}
//	default:
//	{
//		cout << "Введено неверное число"; break;
//	}
//	}
//	return 0;
//}


/**
 * Запрашивает у пользователя количество элементов для списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int Lists::fill_element() {
	int amount_of_elements = 0;
	CheckInput errors;
	std::string temprorary_amount;
	while (true) {
		std::cout << "Введите положительное целое число - количество элементов в списке: ";
		std::getline(std::cin, temprorary_amount);
		if (errors.is_valid_number(temprorary_amount)) {
			amount_of_elements = errors.string_to_int(temprorary_amount);
			if (amount_of_elements <= 0) {
				std::cout << "Ошибка: число должно быть больше 0.\n";
			} else {
				break;
			}
		}
		else {
			std::cout << "Ошибка ввода. Попробуйте ещё раз.\n";
		}
		
	}
	return amount_of_elements;
}

/**
 * Запрашивает у пользователя число для вставки в список.
 *
 * В соответствии с заданием требуется вставить число M
 * в отсортированный список, сохранив упорядоченность.
 * Число может быть любым целым (отрицательным, нулём, положительным),
 * но не должно быть уже в списке.
 *
 * @return Целое число для вставки
 */
int Lists::fill_input_number(PNode& head_copy_list, LinearList& list) {
	int number_to_add;
	CheckInput errors;
	std::string temprorary_amount;

	while (true) {
		std::cout << "Введите целое число - элемент для вставки: ";
		std::getline(std::cin, temprorary_amount);
		if (errors.is_valid_number(temprorary_amount)) {
			number_to_add = errors.string_to_int(temprorary_amount);
			PNode existing_node = list.find_node(head_copy_list, number_to_add);
			if (existing_node != nullptr) {
				std::cout << "Ошибка. Число " << number_to_add << " уже существует в списке." << std::endl;
				continue;
			}

			break;
		}

		std::cout << "Ошибка ввода. Попробуйте ещё раз.\n";
	}
	
	return number_to_add;
}

/**
 * Заполняет исходный список и его копию одинаковыми значениями.
 *
 * По условию задачи необходимо создать копию исходного списка
 * для дальнейших операций (вставка элемента M). Заполнение обоих списков
 * одновременно гарантирует их идентичность в начальный момент времени.
 * Проверка на возрастание при вводе обеспечивает выполнение условия задачи
 * о том, что элементы исходного списка упорядочены по возрастанию.
 *
 * @param amount_of_elements Количество элементов для ввода
 * @param head_original_list Голова исходного списка
 * @param tail_original_list Хвост исходного списка (для эффективной вставки в конец)
 * @param head_copy_list Голова списка-копии
 * @param tail_copy_list Хвост списка-копии
 * @param list Ссылка на объект LinearList для выполнения операций
 */
void Lists::fill_lists(int amount_of_elements, PNode& head_original_list, PNode& tail_original_list,
	PNode& head_copy_list, PNode& tail_copy_list, LinearList& list) {
	int temporary_data;
	int previous_data = INT_MIN;
	CheckInput errors;
	std::string temporary;
	for (int i = 0; i < amount_of_elements; i++) {
		while (true) {
			std::cout << "Введите " << i+1 << " целое число(должно быть больше предыдущего): ";
			std::getline(std::cin, temporary);
			if (errors.is_valid_number(temporary)) {
				temporary_data = errors.string_to_int(temporary);
				if (i > 0 && temporary_data <= previous_data) {
					std::cout << "Ошибка. Число должно быть больше предыдущего (" << previous_data << ")." << std::endl;
					continue;
				}
				break;
			}
		}
		
		previous_data = temporary_data;
		list.add(temporary_data, head_original_list, tail_original_list);
		list.add(temporary_data, head_copy_list, tail_copy_list);
	}
}

/**
 * Управляет процессом удаления элементов из списка-копии.
 *
 * Предоставляет пользователю возможность интерактивного удаления
 * элементов для демонстрации работы со списком. Все проверки ввода
 * необходимы для защиты от некорректных данных и обеспечения стабильной работы.
 * Проверка на существование элемента перед удалением предотвращает попытку
 * удаления несуществующего элемента, которая могла бы привести к ошибке.
 *
 * @param head_copy_list Голова списка-копии
 * @param list Ссылка на объект LinearList
 * @param amount_of_elements Исходное количество элементов (для проверки,
 *        что количество удаляемых элементов не превышает существующее)
 */
void Lists::delete_elements(PNode& head_copy_list, LinearList& list, int amount_of_elements) {
// FIX_ME: Название должно быть осмысленным.		
//int choice;
	int user_choice;
	std::string temporary_choice;
	CheckInput errors;

// FIX_ME: Абсолюнто отсуствует проверка на корректность вводимого числа.
//cout << endl << "Хотите удалить какой-нибудь элемент?" << endl;
//cout << "Если да, то напишите 1" << endl;
//cout << "Если нет, то напишите 2" << endl;
//cout << "Ваш выбор: ";
//cin >> user_choice;
//cout << endl;

	std::cout << "Хотите удалить какой-нибудь элемент?" << std::endl
		<< "Если да, то напишите 1" << std::endl
		<< "Если нет, то напишите 2" << std::endl;
		
	while (true) {
		std::cout << "Ваш выбор: ";
		std::getline(std::cin, temporary_choice);
		if (errors.is_valid_number(temporary_choice)) {
			break;
		}
		std::cout << "Введено неверное значение. Попробуйте снова. " << std::endl;
	}
	user_choice = errors.string_to_int(temporary_choice);

// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.
	switch (user_choice) {
	//{
		case 1: {
		//{
			// FIX_ME: Абсолюнто отсуствует проверка на корректность вводимого числа.
			// FIX_ME: Название должно быть осмысленным.
			// FIX_ME: Отсутствует проверка, где количество удаляемых элементов может быть больше количества всех элементов.
			//cout << "Введите число - количество элементов которое вы хотите удалить: ";
			//cout << "Введите число - количество элементов которое вы хотите удалить: ";
			//int num;
			//cin >> num;

			int user_number;
			std::string temporary_number;
			while (true) {
				std::cout << "Введите число - количество элементов которое вы хотите удалить: ";
				std::getline(std::cin, temporary_number);
				if (errors.is_valid_number(temporary_number)) {
					user_number = errors.string_to_int(temporary_number);
					if (user_number <= 0) {
						std::cout << "Введено неверное значение. Попробуйте снова. " << std::endl;
					}
					else {
						if (user_number > amount_of_elements) {
							std::cout << "Количество элементов для удаления превышает количество существующих элементов." << std::endl;
						}
						else {
							break;
						}
					}
				}
				std::cout << "Введено неверное значение. Попробуйте снова. " << std::endl;
			}

			for (int i = 0; i < user_number; i++) {
				//{
					// FIX_ME: Абсолюнто отсуствует проверка на корректность вводимого числа.
					// FIX_ME: Название должно быть осмысленным.
					//std::cout << "Введите значение элемента, который вы хотите удалить: ";
					//int x;
					//std::cin >> x;
					//PNode p = Find(p3, x);

				int user_input;
				std::string temporary_input;
				while (true) {
					std::cout << "Введите значение элемента, который вы хотите удалить: ";
					std::getline(std::cin, temporary_input);
					if (errors.is_valid_number(temporary_input)) {
						break;
					}
					std::cout << "Введено неверное значение. Попробуйте снова. " << std::endl;
				}
				user_input = errors.string_to_int(temporary_input);
				PNode node_to_find = list.find_node(head_copy_list, user_input);
				// FIX_ME: отсутсвует проверка, где значение элемента отсутствует в списке.
				if (node_to_find == nullptr) {
					std::cout << "Элемент со значением " << user_input << " отсутствует." << std::endl;
					continue;
				}

				std::cout << "Удаление...." << std::endl;
				//DeleteNode(p3, p);
				list.delete_node(head_copy_list, node_to_find);
				break;
			}
			//show2(p3);
			list.show_new_list(head_copy_list);
		}break;
		// FIX_ME: Отсутсвует break.
		case 2: {
			//{
				//{
					// FIX_ME: Завершение работы подзадачи можно написать более официально.
					//std::cout << "Спасибо за терпение!!!" << std::endl;
					//std::cout << "До свидания!!!" << std::endl;
			std::cout << "Завершение работы программы..." << std::endl;
			//}
		//}
		} break;
		default: {
		//{
				std::cout << "Введено неверное число"; break;
		}
	}
}


/**
 * Основной метод, реализующий логику программы согласно заданию.
 *
 * Объединяет все этапы работы в единый процесс, чтобы пользователь
 * мог наглядно увидеть все преобразования данных:
 * 1. Создание исходного списка и его копии - требуется по условию задачи
 * 2. Демонстрация исходного списка - для сравнения с изменённой копией
 * 3. Вставка элемента M в копию - основное требование задачи
 * 4. Демонстрация изменённого списка-копии - для проверки результата
 * 5. Опциональное удаление элементов - для демонстрации дополнительных операций
 */
void Lists::show_work() {

// FIX_ME: SetConsoleCP/SetConsoleOutputCP не рекомендовано использовать в Google Codestyle Guide.
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian.utf8");


// FIX_ME: Название должно быть осмысленным.
//	PNode p1 = nullptr;
//	PNode p2 = nullptr;
//	PNode p3 = nullptr;
//	PNode p4 = nullptr;
//	int n, m;

	PNode head_original_list = nullptr;
	PNode tail_original_list = nullptr;
	PNode head_copy_list = nullptr;
	PNode tail_copy_list = nullptr;
	int amount_of_elements, digit_to_add;

	LinearList list;
	CheckInput errors;

// FIX_ME: Слишком много деталей.
//	cout << "Добро пожаловать!" << endl;
//	cout << "Перед нами последняя задача: " << endl;
//	cout << "Дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << endl;
//	cout << "Необходимо создать копию исходного списка, после чего во вновь созданном списке вставить" << endl;
//	cout << "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << endl << endl;
//	cout << "----------------------------------------------------------------------" << endl << endl;
//	cout << "Вам необхожимо будет ввести количество элементов в списке," << endl;
//	cout << "а позже ввести значения элементов СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ " << endl;
//	cout << "и ввести число которое вы хотите вставить." << endl;
//	cout << "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ 1 2 3 4 5 6" << endl;
//	cout << "---------------------------------------------------------------------" << endl << endl;
	std::cout << "Задание: дан односвязный линейный список. Значения элементов списка упорядочены по возрастанию." << std::endl
		<< "Необходимо создать копию исходного списка, после чего во вновь созданном списке вставить" << std::endl
		<< "значение M так, чтобы он остался упорядоченным и вывести ссылку на первый элемент полученного списка P2." << std::endl << std::endl
		<< "----------------------------------------------------------------------" << std::endl
		<< "Необходимо ввести количество элементов в списке(целое число)," << std::endl
		<< "значения элементов(целые числа) СТРОГО В ПОРЯДКЕ ВОЗРАСТАНИЯ," << std::endl
		<< "и число, которое будет вставлено." << std::endl
		<< "ПРИМЕР ПОРЯДКА ВОЗРАСТАНИЯ 1 2 3 4 5 6" << std::endl
		<< "---------------------------------------------------------------------" << std::endl << std::endl;

//	FIX_ME: Абсолютно отсутсвует проверка на корректность вводимого числа.
//	cout << "Введите число n - количество элементов в списке: ";
//	cin >> n;
	amount_of_elements = fill_element();

// FIX_ME: Абсолюнто отсуствует проверка на корректность вводимого числа.
//	for (int i = 0; i < n; i++)
//	{
//		int j;
//		cin >> j;
//		add(j, p1, p2);
//		add(j, p3, p4);
//	}
	fill_lists(amount_of_elements, head_original_list, tail_original_list,
		head_copy_list, tail_copy_list, list);
//	cout << endl << "Введите " << n << " чисел в порядке возрастания (!!!!): ";



// FIX_ME: 
//	show(p1);
//	cout << endl;
//	PNode P = find(m, p3);
//	newadd(m, P, p3);
//	show(p3);
	list.show(head_original_list);
	std::cout << std::endl;

// FIX_ME: Абсолютно отсуствует проверка на корректность вводимого числа.
//	cout << endl << "Введите целое значение числа m, которое необходимо будет вставить: ";
//	cin >> m;
	digit_to_add = fill_input_number(head_copy_list, list);

	PNode temprorary = list.find(digit_to_add, head_copy_list);
	list.new_add(digit_to_add, temprorary, head_copy_list);
	list.show(head_copy_list);
	
	delete_elements(head_copy_list, list, amount_of_elements);

}