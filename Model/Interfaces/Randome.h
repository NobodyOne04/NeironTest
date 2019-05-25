#pragma once
#include <ctime>
#include "stdlib.h"

/* Класс реализует генерацию рандомных входных сигналов. */
	class Randome
	{
	public:

		/* Конструктор реализует инициализацию генератора случайных чисел. */
		Randome();

		/* Генерация рандомного входного сигнала и запись сигнала в массив сигналов. */
		void randomeX(int& size, int* x, bool& ans);
	};