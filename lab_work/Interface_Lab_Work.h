#pragma once

#include<iostream>
#include<string>
#include <iomanip>

class Interface_Lab_Work // ������� ����� ����� ��� ������ �� ������� � ��������� []
{

public:

	// ����� ������ ���������� � ���������� � �������� ��������� � �����
	virtual void print_information_discipline()	 = 0; // ������� ����� � �������� ������ virtual ��� ����������� ��� ��������������
	virtual int& operator [](int estimation) = 0; // ������� ��������� [] � �������� ������ virtual ��� ����������� ��� ��������������

	virtual ~Interface_Lab_Work() {};
};
