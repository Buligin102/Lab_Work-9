#pragma once

#include "delivery_lab_work.h"

class Student_Lab_Work : public delivery_lab_work // Создание Производного класса, который наледуется от базового класса
{
protected:

	bool *check_otchet = nullptr; // создаем массив для хранения значений о сданном отчете по лабе
	int count_false_otchets; // Кол-во сколько осталось сдать отчетов

public:

	// Конструктор
	Student_Lab_Work(int discipline, int count_lab_work, int* difficult);


	// МЕТОДЫ


	void print_information_discipline() override; // Ключевое слово override позволяет переопределить уже существущий метод в базовом классе
	void set_true_otchet(int num_of_lab); // Метод установки сдан ли отчет по конкрутной лабораторной работе или нет или нет
	int get_cout_false_otchets(); // Метод возвращающий сколько всего отчетов надо ещё сдать
	void enter_info_lab(int number_lab, int estimation) override; // Так же при помощи override переопределяем уже суще Метод вноса информации о сданной оабораторной работе
	


	// Деструктор
	virtual ~Student_Lab_Work(); // Создаем виртуальный деструктор для удаления памяти через констуктор
};

