#pragma once
#include <fstream>
#include <iostream>

using namespace std;

/* ����� ��������� ������ � �������. */
class File
{
public:

	/* ������ ���� � ��������. */
	void readExample(int* data, bool& ans, int size);

	/* ������ ���� �� �����. */
	void readWeight(int* data, int& size);

	/* ���������� ���� ��������� � �������� �������� � ����. */
	void writeWeight(int* data, int& size);
};

