#pragma once

#include <string>

/**
 * Класс CheckInput отвечает за валидацию и преобразование пользовательского ввода.
 *
 * Выделение проверки ввода в отдельный класс следует принципу единственной
 * ответственности и позволяет повторно использовать логику валидации в разных частях программы.
 */
class CheckInput {
public:
	bool is_valid_number(const std::string& string_to_check);
	int string_to_int(const std::string& string_number);
};