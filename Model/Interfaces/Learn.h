#pragma once
#include "Base.h"
#include "Randome.h"

/* Класс реализует обучение нейронной сети. */
class Learn :
	public Base
{
private:
	
	/* Изменение весов. */
	void changeWeight();
public:

	/* Конструктор базового класса. */
	Learn(int size):Base(size) {};

	/* Реализует процесс обучения. */
	void makeLearn(int col);
};

