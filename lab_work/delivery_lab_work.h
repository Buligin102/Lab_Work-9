#pragma once

#include "Interface_Lab_Work.h"

using namespace std;

class delivery_lab_work : public Interface_Lab_Work
{
private:
	enum Discipline{mathematic, programing, informatic}; // enum для Дисциплин
	enum Difficult { easy, medium, hard }; // enum для сложностей	

protected:
	int discipline = 0; // Создаем для того что бы в дальнейшем туда передавать enum значения
	int count_lab_work = 0; // Кол-во всего лабораторных работ
	int* difficulty_work = nullptr; // Массив для хранения сложности лабораторных работ
	int* assessment_lab_work = nullptr; // Массив для оценок по лабораторным работам
	int count_completed_lab_work = 0; // Кол-во сданных лабораторных работ
	float evaluation_dissepline = 0; // Оцнека по дисциплине

public:

	delivery_lab_work(int discipline, int count_lab_work);

	// Конструктор, в который передаем дисциплину класса enum, кол-во лаборатоных работ
	// и массив сложнойстей лаборатоных работ, перегружаем конструктор
	delivery_lab_work(int discipline, int count_lab_work, int* difficult);


	// Гетеры (Селекторы)

	// Получаем значение кол-ва выполненых лаборотоных
	int get_count_completed_lab_work();
	// Получаем значение кол-ва всего лабораторных работ
	int get_count_lab_work();
	// Получаем значение оценки за дисциплину
	float get_evaluation_dissepline();


	// Метод вывода информации о дисциплине и текущему состоянию её сдачи
	void print_information_discipline() override; // используем оператор override для того чтобы в этом классе его переопределить 
	// Метод вноса информации о сданной оабораторной работе
	virtual void enter_info_lab(int number_lab, int estimation);


	// Перегрузка оператора вывода на консоль
	friend std::ostream& operator << (std::ostream& out, const delivery_lab_work& ourObject); 
	// Перегрузка оператора [] для носа оценки, полученной при сдаче лаб работы
	int& operator [](int num_lab) override; // используем оператор override для того чтобы в этом классе его переопределить
	// Перегрузка оператора += для расчета кол-ва несданных работ по дисциплине
	friend void operator+=(int& sum, delivery_lab_work& ourObject);

	// Деструктор для освобождения памяти и удаления динамических массивов
	virtual ~delivery_lab_work() // Создаем виртуальный деструктор для удаления памяти через констуктор
	{
		delete[]difficulty_work;
		delete[]assessment_lab_work;
	}
};

// Перегрузка оператора вывода на консоль
std::ostream& operator << (std::ostream& out, const delivery_lab_work& ourObject); 

// Перегрузка оператора += для расчета кол-ва несданных работ по дисциплине
void operator+=(int& sum, delivery_lab_work& ourObject);

