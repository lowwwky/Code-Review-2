/* Дан двусвязный линейный список и указатель на первый элемент этого
списка. Создать текстовый файл, в который вывести содержимое списка в обратном
порядке. По ходу вывода списка удалять элементы в нем. Числа выводить в одну строку,
разделяя ровно одним пробелом, в конце строки пробел на ставить.


Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен стандартный
набор методов - добавления/удаления/вывода элементов. Во всех задачах обязательно наличие
дружественного интерфейса. Ввод данных с клавиатуры. */




#include <iostream>
#include <fstream>
#include <string>
#include <limits>
//#include <locale>

#include "Errors.h"
#include "ListInitialization.h"
#include "Task04Header.h"

// FIX_ME: В Google Codestyle Guide использование пространство имён std нежелательно.
//using namespace std;


// FIX_ME: Название должно быть осмысленным.
// FIX_ME: в Google Codestyle Guide названия переменных пишутся как lower_case_with_underscores.

// FIX_ME: Лучше использовать отдельные файлы для разных классов.

//// Структура узла двусвязного списка
//struct Uzel {
//    int Dannye;         // Данные узла
//    Uzel* Predydushiy;  // Указатель на предыдущий узел
//    Uzel* Sleduyushiy;  // Указатель на следующий узел
//};
//
//// Класс для работы с двусвязным списком
//class Spisok {
//private:
//    Uzel* Perviy; // Указатель на первый узел
//
//public:
//    // Инициализация списка
//    void Inicializacia() {
//        Perviy = nullptr;
//    }
//
//    // Добавление элемента в конец списка
//    void DobavitElement(int Znachenie) {
//        Uzel* Novyj = new Uzel;
//        Novyj->Dannye = Znachenie;
//        Novyj->Predydushiy = nullptr;
//        Novyj->Sleduyushiy = nullptr;
//
//        if (Perviy == nullptr) {
//            Perviy = Novyj;
//        }
//        else {
//            Uzel* Tekushiy = Perviy;
//            while (Tekushiy->Sleduyushiy != nullptr) {
//                Tekushiy = Tekushiy->Sleduyushiy;
//            }
//            Tekushiy->Sleduyushiy = Novyj;
//            Novyj->Predydushiy = Tekushiy;
//        }
//    }
//
//    // Удаление указанного узла
//    void UdalitElement(Uzel* UzelDlyaUdaleniya) {
//        if (UzelDlyaUdaleniya == nullptr) return;
//
//        Uzel* Pred = UzelDlyaUdaleniya->Predydushiy;
//        Uzel* Sled = UzelDlyaUdaleniya->Sleduyushiy;
//
//        if (Pred != nullptr) {
//            Pred->Sleduyushiy = Sled;
//        }
//        else {
//            Perviy = Sled;
//        }
//
//        if (Sled != nullptr) {
//            Sled->Predydushiy = Pred;
//        }
//
//        delete UzelDlyaUdaleniya;
//    }
//
//    // Вывод списка на экран
//    void Pechat() const {
//        Uzel* Tekushiy = Perviy;
//        cout << "Список: ";
//        while (Tekushiy != nullptr) {
//            cout << Tekushiy->Dannye << " ";
//            Tekushiy = Tekushiy->Sleduyushiy;
//        }
//        cout << endl;
//    }
//
//    // Запись в файл в обратном порядке и удаление элементов
//    void ZapisatVFailIOchistit(const string& ImyaFaila) {
//        ofstream file(ImyaFaila);
//        if (!file.is_open()) {
//            cout << "Ошибка открытия файла!" << endl;
//            return;
//        }
//
//        bool PerviyElement = true;
//        Uzel* Tekushiy = Perviy;
//
//        // Находим последний элемент
//        while (Tekushiy != nullptr && Tekushiy->Sleduyushiy != nullptr) {
//            Tekushiy = Tekushiy->Sleduyushiy;
//        }
//
//        // Записываем и удаляем элементы с конца
//        while (Tekushiy != nullptr) {
//            if (PerviyElement) {
//                file << Tekushiy->Dannye;
//                PerviyElement = false;
//            }
//            else {
//                file << " " << Tekushiy->Dannye;
//            }
//
//            Uzel* Predydushiy = Tekushiy->Predydushiy;
//            UdalitElement(Tekushiy);
//            Tekushiy = Predydushiy;
//        }
//
//        file.close();
//        cout << "Данные записаны в файл и список очищен." << endl;
//    }
//
//    // Очистка всего списка
//    void Ochistka() {
//        Uzel* Tekushiy = Perviy;
//        while (Tekushiy != nullptr) {
//            Uzel* Sleduyushiy = Tekushiy->Sleduyushiy;
//            delete Tekushiy;
//            Tekushiy = Sleduyushiy;
//        }
//        Perviy = nullptr;
//    }
//};

/**
* Запрашивает у пользователя ввод числа с проверкой корректности.
*
* Обеспечивает безопасный ввод целых чисел, проверяя каждый символ
* на принадлежность к цифрам. Поддерживает ввод отрицательных чисел.
* Специальное значение "-1" используется для завершения ввода.
* Функция не завершается, пока не будет введено корректное число
* или специальное значение "-1".
*
* @return Введенное пользователем целое число, или -1 для завершения ввода
* @note Реализует защиту от некорректного ввода (буквы, спецсимволы,
*       пустая строка, минус без цифр и т.д.)
*/
// Функция для ввода числа с проверкой
//int VvodChisla() {
int FileWriter::number_input() {
    //std::string Vvod;
    std::string input_string;
    
    while (true) {
        std::cout << "Введите число (или '-1' для завершения): ";
        std::cin >> input_string;

        if (input_string == "-1") {
            return -1;
        }

        //bool Korrektno = true;
        //int Znak = 1;
        //size_t Start = 0;
        bool correct = true;
        int sign = 1;
        size_t start = 0;

        if (input_string.empty()) {
            correct = false;
        }
        else if (input_string[0] == '-') {
            sign = -1;
            start = 1;
            if (input_string.size() == 1) correct = false;
        }

        for (size_t i = start; i < input_string.size(); ++i) {
            if (!isdigit(input_string[i])) correct = false;
        }

        if (correct) {
            //int Chislo = 0;
            int input_number = 0;
            for (size_t i = start; i < input_string.size(); ++i) {
                input_number = input_number * 10 + (input_string[i] - '0');
            }
            return input_number * sign;
        }
    }
}

/**
* Выводит содержимое файла на экран в отформатированном виде.
*
* Открывает указанный файл для чтения и построчно выводит его содержимое
* в консоль с заголовком "=== Содержимое файла ===". Файл автоматически
* закрывается после завершения чтения. При ошибке открытия файла выводится
* соответствующее сообщение.
*
* @param file_name Имя файла для чтения (может включать путь)
* @note Функция безопасна для использования с несуществующими файлами
*       (выводит сообщение об ошибке и завершается)
*/
// Новая функция для вывода содержимого файла
//void VivodSoderzhimogoFaila(const string& ImyaFaila) {
void FileWriter::show_file_content(const std::string & file_name) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cout << "Ошибка при открытии файла для чтения!" << std::endl;
        return;
    }

    std::cout << "\n=== Содержимое файла ===" << std::endl;
    //string Stroka;
    std::string file_output;
    while (getline(file, file_output)) {
        std::cout << file_output << std::endl;
    }
    file.close();
}

/**
* Организует интерактивный ввод чисел пользователем и добавление их в список.
*
* Предоставляет пользовательский интерфейс для последовательного ввода чисел.
* Ввод продолжается до тех пор, пока пользователь не введет значение "-1".
* Каждое введенное число добавляется в переданный список. Метод использует
* вспомогательную функцию number_input() для проверки корректности ввода.
*
* @param user_list Ссылка на объект списка, в который будут добавляться числа
* @post Список содержит все введенные пользователем числа (кроме -1)
* @see number_input() для деталей проверки вводимых значений
*/
void FileWriter::user_input_to_file(List& user_list) {
    std::cout << "=== Ввод чисел в список ===" << std::endl;
    while (true) {
        //int Chislo = number_input();
        int user_number = number_input();
        if (user_number == -1) break;
        //user_list.DobavitElement(Chislo);
        user_list.add_element(user_number);
    }
}


/**
* Демонстрирует полный цикл работы с пользовательским вводом и файлами.
*
* Основной метод класса, реализующий последовательность операций:
* 1. Вывод условия задания
* 2. Инициализация списка
* 3. Ввод чисел пользователем
* 4. Отображение введенных элементов
* 5. Запрос имени файла и запись в него данных в обратном порядке
* 6. Отображение содержимого созданного файла
* 7. Очистка списка и демонстрация результата
*
* Метод обеспечивает наглядную демонстрацию всех основных операций
* с двусвязным списком и файлами согласно заданию.
*
* @note Метод использует все приватные методы класса для выполнения задач
* @see List класс для работы с двусвязным списком
*/
//int main() {
void FileWriter::show_work() {
    //setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "Russian.utf8");

    // FIX_ME: Название должно быть осмысленным.
    //Spisok MoiSpisok;
    List user_list;
    //user_list.Inicializacia();
    user_list.initialization();
    
    // FIX_ME: Немного непонятна цель задания. Лучше добавить условия.
    std::cout << "Дан двусвязный линейный список и указатель на первый элемент этого" << std::endl
        << "списка.Создать текстовый файл, в который вывести содержимое списка в обратном" << std::endl
        << "порядке.По ходу вывода списка удалять элементы в нем.Числа выводить в одну строку, " << std::endl
        << "разделяя ровно одним пробелом, в конце строки пробел на ставить." << std::endl << std::endl;

    //std::cout << "=== Ввод чисел в список ===" << std::endl;
    //while (true) {
    //    //int Chislo = number_input();
    //    int user_number = number_input();
    //    if (user_number == -1) break;
    //    //user_list.DobavitElement(Chislo);
    //    user_list.add_element(user_number);
    //}

    user_input_to_file(user_list);

    //user_list.Pechat();
    user_list.show_elements();

    std::cout << "\n=== Запись в файл ===" << std::endl;
    //string ImyaFaila;
    std::string file_name;
    //std::cout << "Введите имя файла: ";
    //std::cin >> file_name;

    bool file_written_successfully = false;
    while (!(file_written_successfully)) {
        std::cout << "Введите только имя файла (например, output.txt -> ввести надо output): ";
        std::cin >> file_name;

        if (file_name.find('.') == std::string::npos) {
            file_name += ".txt";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (user_list.write_to_file(file_name)) {
            file_written_successfully = true;
            std::cout << "Данные успешно записаны в файл." << std::endl;
        }
        else {
            std::cout << "Ошибка при открытии файла для записи! Попробуйте снова" << std::endl;
        }
    }

    //user_list.ZapisatVFailIOchistit(ImyaFaila);
    // //user_list.write_to_file(file_name);
    show_file_content(file_name); // Вызов новой функции
    //user_list.Ochistka();
    user_list.clear_list();
    user_list.show_elements();

   // return 0;
}