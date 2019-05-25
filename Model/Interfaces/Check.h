#pragma once
#include "Base.h"
#include <iostream>

/* Класс реализует проверку полученых весов, считает отношение верных предположений к всем. */
class Check :
	public Base
{
public:

	/* Конструктор базового класса. */
	Check(int size):Base(size) {};
	
	/* Подсчет и вывод статистики. */
	void makeCheck(int col);
};

