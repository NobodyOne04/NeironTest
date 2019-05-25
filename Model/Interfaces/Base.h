#pragma once
#include "File.h"
#include "Randome.h"
#include <iostream>

/* Базовый класс реализует методы, используемые в каждом режиме. */
class Base
{
protected:
	File	f; //Экземпляр класса для взаимодействия с файлом.
	int*	weight;
	int*	x;//Входные сигналы.
	bool	ans;//Ожидаемый ответ.
	int		size;
	int 	sum = 0;
	int		lim = 9;//Число активации.
	bool	result;//Предположение нейронки.
	Randome r;
public:

	/* Конструктор, реализующий выделение памяти. */
	Base(int size);

	/* Записывает веса из файла. */
	void setWeight();

	/* Записывает сигналы из файла. */
	void setX();

	/* Сохраняет веса в файл. */
	void saveWeight();

	/* Выводит веса на экран. */
	void getWeight();

	/* Реализует суммарный блок. */
	void makeSum();

	/* Записывает предположение сети в переменную. */
	void makePredict();
};

