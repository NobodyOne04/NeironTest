#include "..\Interfaces\Randome.h"

using namespace std;

/* ����������� ��������� ������������� ���������� ��������� �����. */
Randome::Randome()
{
	srand(time(NULL));
}

/* ��������� ���������� �������� ������� � ������ ������� � ������ ��������. */
void Randome::randomeX(int& size, int* x, bool& ans) 
{
	for (int i = 0;i < size;i++)
		x[i] = rand() % 2;
	ans = false;
}
