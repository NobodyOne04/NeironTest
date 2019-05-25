#include "..\Interfaces\Base.h"

using namespace std;

/* �����������, ����������� ��������� ������. */
	Base::Base(int size) {
		this->x	     = new int[size];
		this->weight = new int[size];
		memset(this->x, 0, size);
		memset(this->weight, 0, size);
		this->size = size;
	}

	/* ���������� ���� �� �����. */
	void Base::setWeight() {
		f.readWeight(this->weight, this->size);
	}

	/* ���������� ������� �� �����. */
	void Base::setX() {
		f.readExample(this->x, this->ans, this->size);
	}

	/* ��������� ���� � ����. */
	void Base::saveWeight() {
		f.writeWeight(this->weight, this->size);
	}

	/* ������� ���� �� �����. */
	void Base::getWeight() {
		for (int i = 0;i < this->size;i++)
			cout << this->weight[i] << " ";
		cout << endl;
	}

	/* ��������� ��������� ����. */
	void Base::makeSum() {
		this->sum = 0;
		for (int i = 0;i < this->size;i++)
			this->sum += this->x[i] * this->weight[i];
	}

	/* ���������� ������������� ���� � ����������. */
	void Base::makePredict() {
		this->makeSum();
		(this->lim > this->sum) ? (this->result = false) : (this->result = true);
	}
