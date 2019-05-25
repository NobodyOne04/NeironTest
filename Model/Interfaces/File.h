#pragma once
#include <fstream>
#include <iostream>

using namespace std;

/* Класс реализует работу с файлами. */
class File
{
public:

	/* Читает файл с примером. */
	void readExample(int* data, bool& ans, int size);

	/* Читает веса из файла. */
	void readWeight(int* data, int& size);

	/* Записывает веса полученые в процессе обучения в файл. */
	void writeWeight(int* data, int& size);
};

