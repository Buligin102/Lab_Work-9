#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <typename T>
class Shablone_Lab
{
private:
	enum Discipline { mathematic, programing, informatic }; // enum ��� ���������
	enum Difficult { easy, medium, hard }; // enum ��� ����������	

protected:
	int discipline = 0; // ������� ��� ���� ��� �� � ���������� ���� ���������� enum ��������
	int count_lab_work = 0; // ���-�� ����� ������������ �����
	int* difficulty_work = nullptr; // ������ ��� �������� ��������� ������������ �����
	int* assessment_lab_work = nullptr; // ������ ��� ������ �� ������������ �������
	int count_completed_lab_work = 0; // ���-�� ������� ������������ �����
	T evaluation_dissepline = 0; // ������ �� ����������

public:

	Shablone_Lab(int discipline, int count_lab_work)
	{
		// ��������� ����������� ��������� ������ � � ������ �� ������������ ������ ������� ���������� throw
		if (count_lab_work < 1)
		{
			throw "�� ��������� ������� ���-�� �����";
		}
		else
		{
			this->count_lab_work = count_lab_work; // ���� ������� �� �����������, �� ��������� ��������� � ��� ���� ������
		}
		if (discipline < 0)
		{
			throw "����� ���������� �� ����� ����";
		}
		else
		{
			this->discipline = discipline;
		}

		assessment_lab_work = new int[count_lab_work]; // ������� ������������ ������ ��� ������ �� ����
		memset(assessment_lab_work, 0, sizeof(int) * count_lab_work); // ��������� ��� ������ �� ���� ������
		difficulty_work = new int[count_lab_work]; // ������� ������������ ������ ��� ������ ���� ��������� ���������
		memset(difficulty_work, 0, sizeof(int) * count_lab_work); // ��������� ������ ������ ����������

	}

	// �����������, � ������� �������� ���������� ������ enum, ���-�� ����������� �����
	// � ������ ����������� ����������� �����, ����������� �����������
	Shablone_Lab(int discipline, int count_lab_work, int* difficult)
	{
		// ������� ���������� �� ���-�� ���, � ������ �������, ��� �� ���-�� ��� �� ���� ������ 1
		if (count_lab_work < 1)
		{
			throw "�� ��������� ������� ���-�� �����";
		}
		else
		{
			this->count_lab_work = count_lab_work; // ���� ������� �� �����������, �� ��������� ��������� � ��� ���� ������
		}

		// ���������� �� ����������� ��������� ����������
		if (discipline < 0)
		{
			throw "����� ���������� �� ����� ����";
		}
		else
		{
			this->discipline = discipline;
		}

		assessment_lab_work = new int[count_lab_work]; // ������� ������������ ������ ��� ������ �� ����
		memset(assessment_lab_work, 0, sizeof(int) * count_lab_work); // ��������� ��� ������ �� ���� ������
		difficulty_work = new int[count_lab_work]; // ������� ������������ ������ ��� ������ ���� ��������� ���������
		// �������� ���������� ������ ��������� ������������ ����� � ������, ����������� � ������
		for (int i = 0; i < count_lab_work; i++)
		{
			difficulty_work[i] = difficult[i];
		}
	}


	// ������ (���������)

	// �������� �������� ���-�� ���������� �����������
	int get_count_completed_lab_work()
	{
		return count_completed_lab_work;
	}
	// �������� �������� ���-�� ����� ������������ �����
	int get_count_lab_work()
	{
		return count_lab_work;
	}
	// �������� �������� ������ �� ����������

	T get_evaluation_dissepline() 
	{
		T sum_estimation = 0; // ���������� ��� �������� ����� ����� ������

		// ���� ��� ������� ����� ���� �����
		for (int i = 0; i < count_lab_work; i++)
		{
			sum_estimation += assessment_lab_work[i];
		}

		evaluation_dissepline = sum_estimation / count_lab_work; // ������� ������� ������ ��� ����������

		return evaluation_dissepline;
	}


	// ����� ������ ���������� � ���������� � �������� ��������� � �����
	void print_information_discipline() // ���������� �������� override ��� ���� ����� � ���� ������ ��� �������������� 
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

		cout << endl << "���-�� ���������� ������������ �����: " << count_completed_lab_work << endl;
		cout << "������ �� ����������: " << fixed << setprecision(4) << get_evaluation_dissepline() << endl;
	}
	// ����� ����� ���������� � ������� ������������ ������
	virtual void enter_info_lab(int number_lab, int estimation)
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
		else
		{
			// ���� �������� �������� �� �������� ��� ������� ����������, �� ����������� ���� else
			assessment_lab_work[number_lab] = estimation; // ����������� �������� ������������ ������ �������� ������
			count_completed_lab_work++; // ����������� ���-�� ���������� ������������ �����
		}
	}


	// ���������� ��������� ������ �� �������
	friend std::ostream& operator << (std::ostream& out, const Shablone_Lab& ourObject)
	{
		// ����� ����������
		out << std::endl << "����������: " << ourObject.discipline;
		// ������� ����� ������������ �����
		out << std::endl << "������������ ������: \t";
		for (int i = 0; i < ourObject.count_lab_work; i++)
		{
			out << "�" << i + 1 << " ";
		}

		// ������� ��������� ��� ������ ������� ������
		out << std::endl << "��������� ������������: ";
		for (int i = 0; i < ourObject.count_lab_work; i++)
		{
			out << ourObject.difficulty_work[i] << "  ";
		}

		// ������� ������ ��� ������ �����������
		out << std::endl << "������ ������������: \t";
		for (int i = 0; i < ourObject.count_lab_work; i++)
		{
			out << ourObject.assessment_lab_work[i] << "  ";
		}

		return out; // ��������� ��� �� ��� �������� out
	}
	// ���������� ��������� [] ��� ���� ������, ���������� ��� ����� ��� ������
	int& operator [](int num_lab) // ���������� �������� override ��� ���� ����� � ���� ������ ��� ��������������
	{
		return assessment_lab_work[num_lab]; // �������������� � ���������� ��������� ������
	}
	// ���������� ��������� += ��� ������� ���-�� ��������� ����� �� ����������
	friend void operator+=(int& sum, Shablone_Lab& ourObject)
	{
		for (int i = 0; i < ourObject.count_lab_work; i++)
		{
			if (ourObject.assessment_lab_work[i] == 0) // ���� ������ ����� 0, �� �� ������� �� ��� �� �������
			{
				sum += 1;
			}
		}
	}

	// ���������� ��� ������������ ������ � �������� ������������ ��������
	virtual ~Shablone_Lab() // ������� ����������� ���������� ��� �������� ������ ����� ����������
	{
		delete[]difficulty_work;
		delete[]assessment_lab_work;
	}
};
