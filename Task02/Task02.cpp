/*
Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди. Извлечь
из очереди N начальных элементов и вывести их значения (если очередь содержит менее N
элементов, то извлечь все ее элементы). Вывести также новые адреса начала и конца очереди
(для пустой очереди дважды вывести nullptr). После извлечения элементов из очереди
освобождать память, которую они занимали.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.


*/


//# include <windows.h>
# include <iostream>

#include "Node.h"
#include "Task02Header.h"
#include "Queues.h"
#include "../../Lab2Task03/Lab2Task03/Errors.h"

// FIX_ME: В Google Codestyle Guide использование пространство имён std нежелательно.
//using namespace std;

//class Node
//{
//public:
//	int data;
//	Node* next;
//};
//typedef Node* PNode;
//
//void add_nodes(int data, PNode& Head, PNode& Tail)
//{
//	PNode Temp;
//	if (Head == NULL)
//	{
//		Head = new Node;
//		Tail = Head;
//		Head->next = NULL;
//
//	}
//	else
//	{
//		Temp = new Node;
//		Tail->next = Temp;
//		Tail = Temp;
//		Tail->next = NULL;
//	}
//	Tail->data = data;
//}
//
//void show_source(PNode head)
//{
//	PNode temp = head;
//	cout << endl << "Исходный адрес первого элемента: " << head << " " << head->data;
//
//	cout << endl << "Исходная очередь: ";
//	while (temp != nullptr)
//	{
//		cout << temp->data << " ";
//		temp = temp->next;
//	}
//
//	PNode last = head;
//	while (last->next != nullptr)
//	{
//		last = last->next;
//	}
//
//	cout << endl << "Исходный адрес последнего элемента: " << last << " " << last->data << endl;
//}
//
//
//
//void delete_nodes(int m, PNode& Head)
//{
//	PNode temp;
//	for (int i = 0; i < m; i++)
//	{
//		temp = Head;
//		cout << temp->data << " " << temp->next << " ";
//		Head = Head->next;
//		delete temp;
//		cout << endl;
//	}
//	cout << endl;
//}
//
//void show_fixed(PNode head)
//{
//	PNode temp = nullptr;
//	PNode temp2 = head;
//	if (head == nullptr)
//	{
//		cout << "Очередь после удаления элементов оказалась пустой" << endl;
//		int* ptr = nullptr;
//		cout << "Начало очереди: " << ptr << endl;
//		cout << "Конец очереди: " << ptr << endl;
//	}
//	else
//	{
//		cout << "Новое начало очереди: " << temp2 << " " << temp2->data << endl;
//		cout << "Оставшиеся элементы очереди: ";
//		while (head != nullptr)
//		{
//			temp = head;
//			cout << temp->data << " ";
//			head = head->next;
//			//delete temp;
//		}
//		cout << endl << "Новый конец очереди: " << temp << " " << temp->data << endl;
//	}
//}


/**
 * Запрашивает у пользователя количество элементов для первого списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int Lists::fill_amount_of_digits() {
    int amount_of_elements = 0;
    CheckInput errors;
    std::string temprorary_amount;
    while (true) {
        std::cout << "Введите целое положительное число m - количество элементов очереди: ";
        std::getline(std::cin, temprorary_amount);
        if (errors.is_valid_number(temprorary_amount)) {
            amount_of_elements = errors.string_to_int(temprorary_amount);
            if (amount_of_elements <= 0) {
                std::cout << "Ошибка: число должно быть больше 0.\n";
            }
            else {
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
 * Запрашивает у пользователя количество элементов для второго списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int Lists::fill_amount_to_delete() {
    int amount_of_elements = 0;
    CheckInput errors;
    std::string temprorary_amount;
    while (true) {
        std::cout << "Введите целое число n(n>0) - количество элементов," << std::endl
            << "очереди, которые нужно извлечь из очереди: " << std::endl;
        std::getline(std::cin, temprorary_amount);
        if (errors.is_valid_number(temprorary_amount)) {
            amount_of_elements = errors.string_to_int(temprorary_amount);
            if (amount_of_elements < 0) {
                std::cout << "Ошибка: число должно быть больше 0.\n";
            }
            else {
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
 * Заполняет очередь указанным количеством элементов, запрашивая их у пользователя.
 *
 * Метод последовательно запрашивает у пользователя целые числа и добавляет их в очередь.
 * Для каждого числа выполняется проверка корректности ввода с использованием
 * вспомогательного класса CheckInput. При неверном вводе пользователю предлагается
 * повторить попытку до получения корректного значения.
 *
 * @param amount_of_elements Количество элементов для добавления в очередь (должно быть положительным)
 * @param pointer_node1 Ссылка на указатель начала очереди (P1)
 * @param pointer_node2 Ссылка на указатель конца очереди (P2)
 * @param queue Ссылка на объект очереди, который будет заполнен элементами
 * @post В очередь добавлено amount_of_elements новых элементов
 * @see CheckInput класс для проверки корректности ввода
 */
void Lists::fill_digits(int amount_of_elements, PNode& pointer_node1, PNode& pointer_node2,Queues& queue) {
    int data;
    CheckInput errors;
    std::string temporary;
    for (int i = 0; i < amount_of_elements; i++) {
        while (true) {
            std::cout << "Введите " << i + 1 << " целое число: ";
            std::getline(std::cin, temporary);
            if (errors.is_valid_number(temporary)) {
                data = errors.string_to_int(temporary);
                queue.add_nodes(data, pointer_node1, pointer_node2);
                break;
            }
            else {
                std::cout << "Ошибка. Введено неверное значение." << std::endl;
            }
        } 
        
    }
     
}

/**
 * Демонстрирует работу с очередью, выполняя последовательность операций.
 *
 * Основной метод класса, реализующий полный сценарий демонстрации работы с очередью:
 * 1. Вывод условия задачи и инструкций для пользователя
 * 2. Запрос количества элементов для создания очереди
 * 3. Заполнение очереди введенными значениями
 * 4. Запрос количества элементов для извлечения из очереди
 * 5. Отображение исходного состояния очереди
 * 6. Извлечение указанного количества элементов из начала очереди
 * 7. Отображение обновленного состояния очереди
 *
 * @note Метод настраивает локаль для корректного отображения русских символов
 * @warning Не рекомендуется использовать SetConsoleCP/SetConsoleOutputCP согласно Google Code Style
 * @see Queues класс для работы с очередью
 * @see fill_amount_of_digits() для ввода количества элементов
 * @see fill_amount_to_delete() для ввода количества удаляемых элементов
 */
//int main()
//{
void Lists::show_work() {
	// FIX_ME: SetConsoleCP/SetConsoleOutputCP не рекомендовано использовать в Google Codestyle Guide.
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian.utf8");

    // FIX_ME: Название должно быть осмысленным.
	/*int m, n;
	PNode p1 = nullptr;
	PNode p2 = nullptr;*/

    int amount_of_digits, amount_to_delete;
    PNode pointer_node1 = nullptr;
    PNode pointer_node2 = nullptr;
    Queues queue;

    // FIX_ME: Можно сократить текст.
	/*cout << "Добро пожаловать!" << endl;
	cout << "Перед нами новая задача:" << endl;
	cout << "Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << endl;
	cout << "Извлечь из очереди N начальных элементов" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Вам необходимо ввести количество элементов очереди и их значения через пробел " << endl;
	cout << "Мы выведем новые адреса начала и конца очереди, извлечем n значений и выведем на экран" << endl;
	cout << endl << endl << "----------------------------------------------------------------------------" << endl;
	cout << "Введите число m - количество элементов очереди: ";*/

    std::cout << "Задача: Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди." << std::endl
        << "Извлечь из очереди N начальных элементов" << std::endl
        << "---------------------------------------------------------" << std::endl
        << "Необходимо ввести количество элементов очереди, их значения," << std::endl
        << "Количество извлекаемых значений." << std::endl;
    
  
    // FIX_ME: Отсутствуют какие-либо проверки начальных значений. Лучше вынести в отдельную функцию.
	/*cin >> m;
	cout << endl << "Введите " << m << " значений элементов очереди через пробел ";
	for (int i = 0; i < m; i++)
	{
		int j;
		cin >> j;
		add(j, p1, p2);
	}*/
	/*cout << endl << endl << "Введите число n(n>0) - количество элементов" << endl;
	cout << "очереди, которые нужно извлечь из очереди: ";
	cin >> n;*/

    amount_of_digits = fill_amount_of_digits();
    fill_digits(amount_of_digits, pointer_node1, pointer_node2, queue);
    amount_to_delete = fill_amount_to_delete();

    /*show1(p1);
    del(n, p1);
    show2(p1);*/

    queue.show_source(pointer_node1);
    queue.delete_nodes(amount_to_delete, pointer_node1);
    queue.show_fixed(pointer_node1);

    //return 0;
}
