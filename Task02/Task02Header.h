#pragma once

#include "Queues.h"
#include "Node.h"

/**
 * Класс, управляющий демонстрацией работы с очередью.
 *
 * Обеспечивает полный цикл взаимодействия с пользователем для
 * демонстрации операций с очередью: ввод количества элементов,
 * заполнение очереди значениями, удаление элементов из начала
 * и отображение результатов. Класс использует вспомогательные
 * методы для проверки корректности ввода и организации
 * пользовательского интерфейса.
 *
 * @note Все методы класса работают в тесной связке с классом Queues
 * @see Queues класс для работы с очередью
 */
class Lists {
private:
	int fill_amount_of_digits();
	int fill_amount_to_delete();
	void fill_digits(int amount_of_elements, PNode& pointer_node1, PNode& pointer_node2, Queues& queue);
public:
	void show_work();
};