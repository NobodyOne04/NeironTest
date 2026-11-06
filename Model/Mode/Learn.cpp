#include "../Interfaces/Learn.h"
#include <iostream>

using namespace std;

bool Learn::changeWeight() {
	makePredict();
	if (result == ans)
		return false;
	// Ложное «да» — ослабляем активные входы и поднимаем порог; ложное «нет» — наоборот.
	const int inc = result ? -1 : 1;
	for (size_t i = 0; i < weight.size(); i++)
		if (x[i] != 0) weight[i] += inc;
	lim -= inc;
	return true;
}

void Learn::makeLearn(int col) {
	setExample();
	const bool resumed = setWeight();
	cout << (resumed ? "Continuing from saved weights" : "No saved weights, starting from zero") << endl;

	int mistakes = 0;
	int lastMistake = -1;
	for (int i = 0; i < col; i++) {
		nextSample(i);
		if (changeWeight()) {
			mistakes++;
			lastMistake = i;
		}
	}
	saveWeight();

	cout << "Iterations: " << col << ", corrections: " << mistakes;
	if (lastMistake >= 0)
		cout << " (last at iteration " << lastMistake + 1 << ")";
	cout << endl;
	getWeight();
}
