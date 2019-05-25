#pragma once
#include "File.h"
#include "Randome.h"
#include <iostream>

/* ������� ����� ��������� ������, ������������ � ������ ������. */
class Base
{
protected:
	File	f; //��������� ������ ��� �������������� � ������.
	int*	weight;
	int*	x;//������� �������.
	bool	ans;//��������� �����.
	int		size;
	int 	sum = 0;
	int		lim = 9;//����� ���������.
	bool	result;//������������� ��������.
	Randome r;
public:

	/* �����������, ����������� ��������� ������. */
	Base(int size);

	/* ���������� ���� �� �����. */
	void setWeight();

	/* ���������� ������� �� �����. */
	void setX();

	/* ��������� ���� � ����. */
	void saveWeight();

	/* ������� ���� �� �����. */
	void getWeight();

	/* ��������� ��������� ����. */
	void makeSum();

	/* ���������� ������������� ���� � ����������. */
	void makePredict();
};

