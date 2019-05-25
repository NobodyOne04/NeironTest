#include <iostream>
#include <cstring>
#include "Interfaces\Learn.h"
#include "Interfaces\Check.h"

using namespace std;

/* Выводит доступные команды. */
void showHelp() {
	cout << "First enter mode: [-learn/-check]" << endl;
	cout << "Second arg must be quantity of iteration like [-iter 200]" << endl;
}

/* Преобразование аргумента в int. */
int convertIteration(char* arg) {
	int iter;
	try {
		iter = atoi(arg);
		throw arg;
	}
	catch (char* arg) {
		std::cout << "Invalid iteration : " << arg << endl;
	}
	return iter;
}

/* Обработка параметров командной строки. */
int main(int argc, char* argv[]) {
	int	 size = 15;
	if (!strcmp(argv[1],"-h")) {
		showHelp();
		return 0;
	};
	if (!strcmp(argv[1],"-learn")) {
		Learn model(size);
		model.makeLearn(convertIteration(argv[3]));
		return 0;
	};
	if (!strcmp(argv[1],"-check")) {
		Check model(size);
		model.makeCheck(convertIteration(argv[3]));
		return 0;
	};
	cout << "put -h to show help" << endl;
	return 0;
}
