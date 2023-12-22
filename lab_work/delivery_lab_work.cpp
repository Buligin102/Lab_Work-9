#include "delivery_lab_work.h"

// ����������� � ����������� ��������� � ����������� ��� �����
delivery_lab_work::delivery_lab_work(int discipline, int count_lab_work)
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

// ���������� ������������
// �����������, � ������� �������� ���������� ������ enum, ���-�� ����������� �����
// � ������ ����������� ����������� �����
delivery_lab_work::delivery_lab_work(int discipline, int count_lab_work, int *difficult)
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


// ������ (������)

// �������� �������� ���-�� ���������� �����������
int delivery_lab_work::get_count_completed_lab_work()
{
	return count_completed_lab_work;
}

// �������� �������� ���-�� ����� ������������ �����
int delivery_lab_work::get_count_lab_work()
{
	return count_lab_work;
}

// �������� �������� ������ �� ����������
float delivery_lab_work::get_evaluation_dissepline()
{
	float sum_estimation = 0; // ���������� ��� �������� ����� ����� ������
	
	// ���� ��� ������� ����� ���� �����
	for (int i = 0; i < count_lab_work; i++)
	{
		sum_estimation += assessment_lab_work[i];
	}

	evaluation_dissepline = sum_estimation / count_lab_work; // ������� ������� ������ ��� ����������

	return evaluation_dissepline;
}


// ����� ������ ���������� � ���������� � �������� ��������� � �����
void delivery_lab_work::print_information_discipline()
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
	cout << "������ �� ����������: " << get_evaluation_dissepline() << endl;
}


// ����� ����� ���������� � ������� ������������ ������
void delivery_lab_work::enter_info_lab(int number_lab, int estimation)
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

// ���������� ��������� ������
std::ostream& operator<<(std::ostream& out, const delivery_lab_work& ourObject)
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
// ���������� ��������� [] ��� ����� ������, ���������� ��� ����� ��� ������
int& delivery_lab_work::operator [](int num_lab)
{
	return assessment_lab_work[num_lab]; // �������������� � ���������� ��������� ������
}

// ���������� ��������� += ��� ������� ���-�� ��������� ����� �� ����������
void operator +=(int& sum, delivery_lab_work& ourObject)
{
	for (int i = 0; i < ourObject.count_lab_work; i++)
	{
		if (ourObject.assessment_lab_work[i] == 0) // ���� ������ ����� 0, �� �� ������� �� ��� �� �������
		{
			sum += 1; 
		}
	}
}
