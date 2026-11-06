#pragma once
#include <random>
#include <vector>

/* Класс реализует генерацию случайных входных сигналов. */
class Randome
{
public:
	/* Конструктор реализует инициализацию генератора случайных чисел. */
	Randome();

	/* Заполняет x случайными сигналами 0/1, гарантированно отличными от exclude (эталонного примера). */
	void randomeX(std::vector<int>& x, const std::vector<int>& exclude);

private:
	std::mt19937 gen;
};
