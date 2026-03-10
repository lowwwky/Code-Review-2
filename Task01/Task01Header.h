#pragma once

#include "Stack.h"

/**
 * Класс, управляющий демонстрацией работы со стеком.
 *
 * Предоставляет методы для организации пользовательского интерфейса,
 * ввода данных и отображения результатов операций со стеком.
 * Класс инкапсулирует логику взаимодействия с пользователем и
 * делегирует операции со стеком соответствующему классу Stack.
 */
class StackWork {
private:
	int fill_amount_of_digits();
	void fill_stack(int amount_of_elements, Stack& stack);
public:
	void show_work();
};