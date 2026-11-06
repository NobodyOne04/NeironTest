#include "../Interfaces/Base.h"
#include <iostream>

using namespace std;

Base::Base(int size, const string& dataDir)
	: f(dataDir), weight(size, 0), example(size, 0), x(size, 0) {}

bool Base::setWeight() {
	return f.readWeight(weight, lim);
}

void Base::setExample() {
	f.readExample(example, exampleAns);
}

void Base::saveWeight() const {
	f.writeWeight(weight, lim);
}

void Base::getWeight() const {
	cout << "Weights:";
	for (int w : weight)
		cout << " " << w;
	cout << "\nThreshold: " << lim << endl;
}

void Base::nextSample(int i) {
	if (i % 3 == 0) {
		x = example;
		ans = exampleAns;
	}
	else {
		r.randomeX(x, example);
		ans = false;
	}
}

void Base::makeSum() {
	sum = 0;
	for (size_t i = 0; i < weight.size(); i++)
		sum += x[i] * weight[i];
}

void Base::makePredict() {
	makeSum();
	result = sum >= lim;
}
