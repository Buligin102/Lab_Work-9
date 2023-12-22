#include "Student_Lab_Work.h"


// ����������� � �����������


// �����������
Student_Lab_Work::Student_Lab_Work(int discipline, int count_lab_work, int* difficult)
	: delivery_lab_work(discipline, count_lab_work, difficult)  // ��� �������� � ������������ ����������, ��� ����� ���������� � ����������� �������� ������, ��� ������� ����� �� ����� ����������
{
	count_false_otchets = count_lab_work; // ������� ��� ���-�� �� ������� ������� ����� ���-�� ����� �������

	check_otchet = new bool[count_lab_work]; // �������� ������ ��� ������
	for (int i = 0; i < count_lab_work; i++) // ������� ��� ��� ������ ���� ��� �� �����
	{
		check_otchet[i] = false;
	}
}

// ����������
Student_Lab_Work::~Student_Lab_Work() // ���������� ������������ ������ ���������� ��� ������������ ������
{
	delete[] check_otchet;
}


// ������


// ���������������� ����� ������  �� ������� ��� ������������ ������ � ������ ����� ������
void Student_Lab_Work::print_information_discipline() // �������������� ����� ������ ��� ������������ ������
{
	cout << "\n\n����������: " << discipline << endl;
	cout << "���-�� ������������ �����: " << count_lab_work << endl;
	cout << "\n������ �� ������������ ������: " << setw(5);

	// ������� �� ��������� ������ ������������ �����
	for (int i = 0; i < count_lab_work; i++)
	{
		cout << assessment_lab_work[i] << " ";
	}

	cout << endl << "\n��������� ������������ �����: " << setw(5);

	// ������� �� ��������� �������� ���������� ������������ �����
	for (int i = 0; i < count_lab_work; i++)
	{
		cout << difficulty_work[i] << " ";
	}

	cout << endl << "\n���������� ������� �������: " << setw(10);

	for (int i = 0; i < count_lab_work; i++)
	{
		cout << boolalpha << check_otchet[i] << " "; // � ������� boolalpha ������� bool �������� � �� �����
	}

	cout << endl << "\n���-�� ���������� ������������ �����: " << get_count_completed_lab_work();
	cout << endl << "������� �������� ����� �������: " << count_false_otchets << endl;
	cout << "\n\n������ �� ����������: " << get_evaluation_dissepline() << endl;
}

// ����� ��������� ���� �� ����� �� ���������� ������������ ������ ��� ��� ��� ��� 
void Student_Lab_Work::set_true_otchet(int num_of_lab)
{
	check_otchet[num_of_lab] = true; // ������� ��� ����� �� ���������� ���� ���� � ������ ��� true 
	count_false_otchets--;
}

// ����� ������������ ������� ����� ������� ���� ��� �����
int Student_Lab_Work::get_cout_false_otchets()
{
	return count_false_otchets;
}

// ���������������� ����� ����� ���������� � ������� ������������ ������
void Student_Lab_Work::enter_info_lab(int number_lab, int estimation)
{

	// ����������� throw
	if (number_lab > count_lab_work - 1)
	{
		throw "����� ����������� �� ����� ���� ������ ���-�� �����������";
	}
	if (number_lab < 0)
	{
		throw "����� ������������ �� ����� ���� ������ 0";
	}
	if (estimation < 1)
	{
		throw "������ �� ������������ ������ �� ����� ���� ������ 1-���";
	}
	if (estimation > 5)
	{
		throw "������ �� ������������ ������ �� ����� ���� ������ 5-�";
	}
	if (check_otchet[number_lab] == true) // ��������� �� ������� �� �������, ���� ���� ����� �� ������ ����, �� ���� ����� ����� ���
	{
		// ���� �������� �������� �� �������� ��� ������� ����������, �� ����������� ���� else
		assessment_lab_work[number_lab] = estimation; // ����������� �������� ������������ ������ �������� ������
		count_completed_lab_work++; // ����������� ���-�� ���������� ������������ �����
	}
	else // ���� ������� �� ����������� ������ � ������ ���������� ������ �� ������
	{
		cout << "����� �� ���� ������������ ������ �� ���� (" << endl;
	}
}