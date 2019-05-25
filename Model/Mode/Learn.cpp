#include "..\Interfaces\Learn.h"

/* Изменение весов. */
void Learn::changeWeight() {
	Base::makePredict();
	if (Base::result == Base::ans)return;
	int inc = 0;
	(Base::result == true) ? (inc = -1) : (inc = 1);
	for (int i = 0;i < Base::size;i++)
		if (Base::x[i] != 0) Base::weight[i] += inc;
}

/* Реализует процесс обучения. */
void Learn::makeLearn(int col) {
	for (int i = 0;i < col;i++) {
		if (i % 3 == 0) {
			Base::setX();
			Base::setWeight();
			this->changeWeight();
		}
		else {
			Base::setX();
			Base::r.randomeX(Base::size, Base::x, Base::ans);
			this->changeWeight();
		}
		Base::saveWeight();
	}
}
