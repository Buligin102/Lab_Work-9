#pragma once

#include "delivery_lab_work.h"

class Student_Lab_Work : public delivery_lab_work // �������� ������������ ������, ������� ���������� �� �������� ������
{
protected:

	bool *check_otchet = nullptr; // ������� ������ ��� �������� �������� � ������� ������ �� ����
	int count_false_otchets; // ���-�� ������� �������� ����� �������

public:

	// �����������
	Student_Lab_Work(int discipline, int count_lab_work, int* difficult);


	// ������


	void print_information_discipline() override; // �������� ����� override ��������� �������������� ��� ����������� ����� � ������� ������
	void set_true_otchet(int num_of_lab); // ����� ��������� ���� �� ����� �� ���������� ������������ ������ ��� ��� ��� ���
	int get_cout_false_otchets(); // ����� ������������ ������� ����� ������� ���� ��� �����
	void enter_info_lab(int number_lab, int estimation) override; // ��� �� ��� ������ override �������������� ��� ���� ����� ����� ���������� � ������� ������������ ������
	


	// ����������
	virtual ~Student_Lab_Work(); // ������� ����������� ���������� ��� �������� ������ ����� ����������
};

