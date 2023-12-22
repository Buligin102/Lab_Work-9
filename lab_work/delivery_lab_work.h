#pragma once

#include "Interface_Lab_Work.h"

using namespace std;

class delivery_lab_work : public Interface_Lab_Work
{
private:
	enum Discipline{mathematic, programing, informatic}; // enum ��� ���������
	enum Difficult { easy, medium, hard }; // enum ��� ����������	

protected:
	int discipline = 0; // ������� ��� ���� ��� �� � ���������� ���� ���������� enum ��������
	int count_lab_work = 0; // ���-�� ����� ������������ �����
	int* difficulty_work = nullptr; // ������ ��� �������� ��������� ������������ �����
	int* assessment_lab_work = nullptr; // ������ ��� ������ �� ������������ �������
	int count_completed_lab_work = 0; // ���-�� ������� ������������ �����
	float evaluation_dissepline = 0; // ������ �� ����������

public:

	delivery_lab_work(int discipline, int count_lab_work);

	// �����������, � ������� �������� ���������� ������ enum, ���-�� ����������� �����
	// � ������ ����������� ����������� �����, ����������� �����������
	delivery_lab_work(int discipline, int count_lab_work, int* difficult);


	// ������ (���������)

	// �������� �������� ���-�� ���������� �����������
	int get_count_completed_lab_work();
	// �������� �������� ���-�� ����� ������������ �����
	int get_count_lab_work();
	// �������� �������� ������ �� ����������
	float get_evaluation_dissepline();


	// ����� ������ ���������� � ���������� � �������� ��������� � �����
	void print_information_discipline() override; // ���������� �������� override ��� ���� ����� � ���� ������ ��� �������������� 
	// ����� ����� ���������� � ������� ������������ ������
	virtual void enter_info_lab(int number_lab, int estimation);


	// ���������� ��������� ������ �� �������
	friend std::ostream& operator << (std::ostream& out, const delivery_lab_work& ourObject); 
	// ���������� ��������� [] ��� ���� ������, ���������� ��� ����� ��� ������
	int& operator [](int num_lab) override; // ���������� �������� override ��� ���� ����� � ���� ������ ��� ��������������
	// ���������� ��������� += ��� ������� ���-�� ��������� ����� �� ����������
	friend void operator+=(int& sum, delivery_lab_work& ourObject);

	// ���������� ��� ������������ ������ � �������� ������������ ��������
	virtual ~delivery_lab_work() // ������� ����������� ���������� ��� �������� ������ ����� ����������
	{
		delete[]difficulty_work;
		delete[]assessment_lab_work;
	}
};

// ���������� ��������� ������ �� �������
std::ostream& operator << (std::ostream& out, const delivery_lab_work& ourObject); 

// ���������� ��������� += ��� ������� ���-�� ��������� ����� �� ����������
void operator+=(int& sum, delivery_lab_work& ourObject);

