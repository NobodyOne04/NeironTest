#pragma once
#include "Base.h"

/* Класс реализует обучение нейронной сети (правило перцептрона). */
class Learn :
	public Base
{
private:
	/* Изменение весов и порога. Возвращает true, если сеть ошиблась. */
	bool changeWeight();

public:
	using Base::Base;

	/* Реализует процесс обучения на col образцах. */
	void makeLearn(int col);
};
