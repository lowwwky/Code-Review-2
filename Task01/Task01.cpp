/*Дано число D и указатель P1 на вершину непустого стека.
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

#include <iostream>

#include "Stack.h"
#include "Task01Header.h"
#include "../../Lab2Task03/Lab2Task03/Errors.h"

// #include <Windows.h>

// FIX_ME: В Google Codestyle Guide использование пространство имён std нежелательно.
//using namespace std;

// FIX_ME: В Google Codestyle Guide классы нужно разделять на отдельные файлы.
/*class Node
{
public:
    int x;          // Значение узла
    Node* next;     // Указатель на следующий узел

    Node(int d) : x(d), next(nullptr) {}
};

class Stack
{
private:
    Node* top; // Указатель на вершину стека

public:
    Stack() : top(nullptr) {}

    void push(int d)
    {
        Node* newNode = new Node(d); // Создаем новый узел
        newNode->next = top; // Новый узел указывает на старую вершину
        top = newNode; // Новый узел становится вершиной стека
    }

    void show() const
    {
        Node* current = top;
        while (current != nullptr)
        {
            //cout << current->x << " ";
            std::cout << current->x << " ";
            current = current->next;
        }
        //cout << endl;
        std::cout << std::endl;
    }

    void showAddress() const
    {
        //cout << "Адрес вершины стека: " << top << endl;
        std::cout << "Адрес вершины стека: " << top << std::endl;
    }
    int getTopValue() const
    {
        if (top != nullptr)
        {
            return top->x;
        }
        return 1;
    }
    bool isEmpty() const
    {
        return top == nullptr;
    }
};
*/


/**
 * Запрашивает у пользователя количество элементов для первого списка.
 *
 * Необходимо убедиться, что пользователь вводит корректное
 * положительное число, так как отрицательное количество элементов
 * или ноль не имеют смысла для создания списка.
 *
 * @return Положительное целое число - количество элементов
 */
int StackWork::fill_amount_of_digits() {
    // FIX_ME: названия переменных должны быть информативными.
    // int N, n;
    int amount_of_elements = 0;
    CheckInput errors;
    std::string temprorary_amount;

    // FIX_ME: формулировка предложения нечеткая.
    // FIX_ME: отсутсвуют какие либо проверки вводимых данных.
    //cout << "Сколько чисел вы хотите, чтобы было в стеке? ";
    //cin >> N;

    while (true) {
        std::cout << "Введите целое положительное число m - количество переменных в стеке: ";
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
 * Заполняет стек указанным количеством элементов, запрашивая их у пользователя.
 *
 * @param amount_of_elements Количество элементов для добавления в стек (должно быть положительным)
 * @param stack Ссылка на объект стека, который будет заполнен элементами
 */
void StackWork::fill_stack(int amount_of_elements, Stack& stack) {
    int data;
    CheckInput errors;
    std::string temporary;
    for (int i = 0; i < amount_of_elements; i++) {
        while (true) {
            std::cout << "Введите " << i + 1 << " целое число: ";
            std::getline(std::cin, temporary);
            if (errors.is_valid_number(temporary)) {
                data = errors.string_to_int(temporary);
                stack.push(data);
                break;
            }
            else {
                std::cout << "Ошибка. Введено неверное значение." << std::endl;
            }
        }

    }
}


/**
 * Демонстрирует работу со стеком, выполняя последовательность операций.
 *
 * Метод реализует основной сценарий работы программы:
 * 1. Запрашивает у пользователя количество элементов для создания стека
 * 2. Заполняет стек введенными значениями
 * 3. Отображает адреса элементов стека и их содержимое
 * 4. Добавляет новый элемент в стек по запросу пользователя
 * 5. Отображает обновленное состояние стека
 * 6. Выполняет удаление стека
 *
 * @note Метод использует setlocale для корректного отображения русских символов
 */
// FIX_ME: Открывающаяся скобка должна располагаться на той же строке, что и объявление функции.
void StackWork::show_work() {
    // FIX_ME: Использование SetConsoleCP/SetConsoleOutputCP не приветсвуется в Google Codestyle Guide.
    // FIX_ME: 
    //setlocale(LC_ALL, "Russian");
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian.utf8");

    // FIX_ME: лучше разбивать куски кода на отдельные элементы.
    //Stack stack;
    //int N, n;
    //cout << "Сколько чисел вы хотите, чтобы было в стеке? ";
    //cin >> N;
    //for (int i = 0; i < N; i++)
    //{
        //cout << "Введите число " << i + 1 << ": ";
        //cin >> n;
        //stack.push(n);
    //}
    // stack.showAddress();

    int amount_of_elements;

    amount_of_elements = fill_amount_of_digits();

    Stack stack;
    fill_stack(amount_of_elements, stack);

    stack.show_address();
    //cout << "Элементы в стеке: ";
    std::cout << "Элементы в стеке: ";
    stack.show();
    int D;
    //cout << "Введите значение D для добавления в стек: ";
    //cin >> D;
    std::cout << "Введите значение D для добавления в стек: ";
    std::cin >> D;
    stack.push(D);
    //cout << "Элементы в новом стеке: ";
    std::cout << "Элементы в новом стеке: ";
    stack.show();
    
    //stack.showAddress();
    stack.show_address();
    //if (!stack.isEmpty()) {
    if (!stack.is_empty()) {
    //{
        //cout << "Значение новой вершины: " << stack.getTopValue() << endl;
        std::cout << "Значение новой вершины: " << stack.get_top_value() << std::endl;
    } else {
    //{
        //cout << "Стек пуст!" << endl;
        std::cout << "Стек пуст!" << std::endl;
    }
    
    std::cout << "Удаление стека..." << std::endl;
    stack.delete_data(stack);
    /*if (!stack.is_empty()) {
        std::cout << "Значение новой вершины: " << stack.get_top_value() << std::endl;
    }
    else {
        std::cout << "Стек пуст!" << std::endl;
    }*/
    std::cout << "Стек пуст!" << std::endl;

    //return 0;
}