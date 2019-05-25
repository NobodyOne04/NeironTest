#include "..\Interfaces\Base.h"

using namespace std;

/* Конструктор, реализующий выделение памяти. */
	Base::Base(int size) {
		this->x	     = new int[size];
		this->weight = new int[size];
		memset(this->x, 0, size);
		memset(this->weight, 0, size);
		this->size = size;
	}

	/* Записывает веса из файла. */
	void Base::setWeight() {
		f.readWeight(this->weight, this->size);
	}

	/* Записывает сигналы из файла. */
	void Base::setX() {
		f.readExample(this->x, this->ans, this->size);
	}

	/* Сохраняет веса в файл. */
	void Base::saveWeight() {
		f.writeWeight(this->weight, this->size);
	}

	/* Выводит веса на экран. */
	void Base::getWeight() {
		for (int i = 0;i < this->size;i++)
			cout << this->weight[i] << " ";
		cout << endl;
	}

	/* Реализует суммарный блок. */
	void Base::makeSum() {
		this->sum = 0;
		for (int i = 0;i < this->size;i++)
			this->sum += this->x[i] * this->weight[i];
	}

	/* Записывает предположение сети в переменную. */
	void Base::makePredict() {
		this->makeSum();
		(this->lim > this->sum) ? (this->result = false) : (this->result = true);
	}
