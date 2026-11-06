#pragma once
#include "File.h"
#include "Randome.h"
#include <string>
#include <vector>

/* Базовый класс реализует методы, используемые в каждом режиме. */
class Base
{
protected:
	File	f; //Экземпляр класса для взаимодействия с файлом.
	Randome r;
	std::vector<int> weight;
	std::vector<int> example;//Эталонный пример из example.txt.
	bool	exampleAns = true;//Ожидаемый ответ для эталона.
	std::vector<int> x;//Текущие входные сигналы.
	bool	ans = false;//Ожидаемый ответ для текущих сигналов.
	int		sum = 0;
	int		lim = 9;//Порог активации (обучается вместе с весами).
	bool	result = false;//Предположение нейронки.

public:
	/* Конструктор: size — число входов, dataDir — папка с данными. */
	Base(int size, const std::string& dataDir);

	/* Загружает веса и порог из файла. Возвращает false, если файла весов нет. */
	bool setWeight();

	/* Загружает эталонный пример из файла. */
	void setExample();

	/* Сохраняет веса в файл. */
	void saveWeight() const;

	/* Выводит веса и порог на экран. */
	void getWeight() const;

	/* Готовит i-й образец: каждый третий — эталон, остальные — случайный шум с ответом «нет». */
	void nextSample(int i);

	/* Реализует суммарный блок. */
	void makeSum();

	/* Записывает предположение сети в переменную. */
	void makePredict();
};
