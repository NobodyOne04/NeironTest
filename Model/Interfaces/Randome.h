#pragma once
#include <ctime>
#include "stdlib.h"

/* ����� ��������� ��������� ��������� ������� ��������. */
	class Randome
	{
	public:

		/* ����������� ��������� ������������� ���������� ��������� �����. */
		Randome();

		/* ��������� ���������� �������� ������� � ������ ������� � ������ ��������. */
		void randomeX(int& size, int* x, bool& ans);
	};