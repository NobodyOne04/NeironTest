#pragma once
#include "Base.h"
#include <iostream>

/* ����� ��������� �������� ��������� �����, ������� ��������� ������ ������������� � ����. */
class Check :
	public Base
{
public:

	/* ����������� �������� ������. */
	Check(int size):Base(size) {};
	
	/* ������� � ����� ����������. */
	void makeCheck(int col);
};

