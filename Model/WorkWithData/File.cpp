#include "..\Interfaces\File.h"

/* Читает файл с примером. */
void File::readExample(int* x, bool& ans, int size) {
	ifstream input;
	input.open("..\Data\example.txt");
	int buff;
	for (int i = 0;i < size;i++) {
		input >> buff;
		x[i] = buff;
	}
	input >> ans;
	input.close();
}

/* Читает веса из файла. */
void File::readWeight(int* weight, int& size) {
	ifstream input;
	input.open("..\Data\weight.txt");
	int buff;
	input >> size;
	for (int i = 0;i < size;i++) {
		input >> buff;
		weight[i] = buff;
	}
	input.close();
}

/* Записывает веса полученые в процессе обучения в файл. */
void File::writeWeight(int* weight, int& size) {
	ofstream output;
	output.open("..\Data\weight.txt");
	output << size << endl;
	for (int i = 0;i < size;i++)
		output << weight[i] << " ";
	output.close();
}
