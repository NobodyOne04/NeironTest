#include "..\Interfaces\Randome.h"

using namespace std;

/* Конструктор реализует инициализацию генератора случайных чисел. */
Randome::Randome()
{
	srand(time(NULL));
}

/* Генерация рандомного входного сигнала и запись сигнала в массив сигналов. */
void Randome::randomeX(int& size, int* x, bool& ans) 
{
	for (int i = 0;i < size;i++)
		x[i] = rand() % 2;
	ans = false;
}
