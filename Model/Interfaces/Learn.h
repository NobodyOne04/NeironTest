#pragma once
#include "Base.h"
#include "Randome.h"

/* ����� ��������� �������� ��������� ����. */
class Learn :
	public Base
{
private:
	
	/* ��������� �����. */
	void changeWeight();
public:

	/* ����������� �������� ������. */
	Learn(int size):Base(size) {};

	/* ��������� ������� ��������. */
	void makeLearn(int col);
};

