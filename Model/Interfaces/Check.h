#pragma once
#include "Base.h"

/* Класс реализует проверку полученых весов, считает отношение верных предположений к всем. */
class Check :
	public Base
{
public:
	using Base::Base;

	/* Подсчет и вывод статистики на col образцах. verbose — печатать каждый ответ. */
	void makeCheck(int col, bool verbose);
};
