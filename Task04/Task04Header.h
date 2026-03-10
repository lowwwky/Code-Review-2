#pragma once

#include "ListInitialization.h"

/**
 * Класс, управляющий вводом данных от пользователя и работой с файлами.
 *
 * Предоставляет методы для организации пользовательского интерфейса,
 * ввода чисел с проверкой корректности, записи данных в файл и
 * отображения содержимого файлов. Класс инкапсулирует логику
 * взаимодействия с пользователем и файловой системой.
 */
class FileWriter {
private:
	void user_input_to_file(List& user_list);
	void show_file_content(const std::string& file_name);
	int number_input();
public:
	void show_work();
};