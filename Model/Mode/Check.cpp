#include "..\Interfaces\Check.h"

/* Подсчет и вывод статистики. */
void Check::makeCheck(int col) {
	float rights = 0.0;
	for (int i = 0;i < col;i++) {
		if (i % 3 == 0) {
			Base::setX();
			Base::setWeight();
			Base::makePredict();
		}
		else {
			Base::setX();
			Base::r.randomeX(Base::size, Base::x, Base::ans);
			Base::makePredict();
		}
		if (Base::result == Base::ans)rights++;
		cout << "Predict: " << Base::result << " " << "Ansver: " << Base::ans << endl;
	}
	rights /= col;
	cout << "Result : " << rights;
}
