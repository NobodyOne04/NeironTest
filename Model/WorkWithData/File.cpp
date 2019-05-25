#include "..\Interfaces\File.h"

/* ������ ���� � ��������. */
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

/* ������ ���� �� �����. */
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

/* ���������� ���� ��������� � �������� �������� � ����. */
void File::writeWeight(int* weight, int& size) {
	ofstream output;
	output.open("..\Data\weight.txt");
	output << size << endl;
	for (int i = 0;i < size;i++)
		output << weight[i] << " ";
	output.close();
}
