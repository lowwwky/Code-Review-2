#include <cctype>
#include <iostream>
#include <string>

#include "Errors.h"

/**
 * Проверяет, является ли строка корректным целым числом.
 *
 * Пользовательский ввод может содержать любые символы, поэтому
 * необходима тщательная проверка перед преобразованием. Функция учитывает:
 * - Пустые строки (недопустимы)
 * - Одиночный знак минус (недопустим)
 * - Наличие нецифровых символов (недопустимы)
 * - Знак минус только в начале строки
 *
 * Использование unsigned char в isdigit() обязательно для корректной
 * обработки символов с кодами >127, которые могут появиться при вводе.
 *
 * @param string_to_check Строка для проверки
 * @return true, если строка содержит целое число, иначе false
 */
bool CheckInput::is_valid_number(const std::string& string_to_check) {

    if (string_to_check.empty()) {
        return false;
    }

    size_t start = 0;

    // Разрешаем минус только вначале.
    if (string_to_check[0] == '-') {
        if (string_to_check.size() == 1) {
            return false;
        }
        start = 1;
    }

    for (size_t i = start; i < string_to_check.size(); i++) {
        if (!isdigit(static_cast<unsigned char>(string_to_check[i]))) {
            return false;
        }
    }

    return true;
}

/**
 * Преобразует строку в целое число.
 *
 * Инкапсуляция std::stoi позволяет централизованно обрабатывать
 * возможные исключения. Функция должна вызываться только после проверки
 * is_valid_number() для гарантии корректности входных данных.
 *
 * Возврат -1 при ошибке является безопасным значением, так как:
 * 1. Это невалидное значение для большинства случаев использования
 * 2. Вызывающий код должен проверять валидность перед вызовом
 *
 * @param string_number Строка, содержащая целое число
 * @return Целое число или -1 при ошибке валидации
 */
int CheckInput::string_to_int(const std::string& string_number) {
    if (!is_valid_number(string_number)) {
        return -1;
    }

    return std::stoi(string_number);
}