#include "Student_Lab_Work.h"


// КОНСТРУКТОР И ДЕСТРУКТОРЫ


// Конструктор
Student_Lab_Work::Student_Lab_Work(int discipline, int count_lab_work, int* difficult)
	: delivery_lab_work(discipline, count_lab_work, difficult)  // При указании в конструкторе параметров, они будут отправлены в конструктор базового класса, где базовый класс их потом обработает
{
	count_false_otchets = count_lab_work; // Говорим что кол-во не сданных отчетов равно кол-ву всего отчетов

	check_otchet = new bool[count_lab_work]; // Выделяем память под отчеты
	for (int i = 0; i < count_lab_work; i++) // Говорим что все отчеты пока что не сданы
	{
		check_otchet[i] = false;
	}
}

// Деструктор
Student_Lab_Work::~Student_Lab_Work() // Освобждаем динамическую память выделяемую под динамический массив
{
	delete[] check_otchet;
}


// МЕТОДЫ


// Переопределенный метод вывода  на консоль для производного класса с учетом сдачи отчета
void Student_Lab_Work::print_information_discipline() // Переопределяем метод вывода для производного класса
{
	cout << "\n\nДисциплина: " << discipline << endl;
	cout << "Кол-во лабораторных работ: " << count_lab_work << endl;
	cout << "\nОценки за лабораторные работы: " << setw(5);

	// Выводим по элементно оценки лабораторных работ
	for (int i = 0; i < count_lab_work; i++)
	{
		cout << assessment_lab_work[i] << " ";
	}

	cout << endl << "\nСложность лабораторных работ: " << setw(5);

	// Выводим по элементно значения сложностей лабороторных работ
	for (int i = 0; i < count_lab_work; i++)
	{
		cout << difficulty_work[i] << " ";
	}

	cout << endl << "\nКоличество сданных отчетов: " << setw(10);

	for (int i = 0; i < count_lab_work; i++)
	{
		cout << boolalpha << check_otchet[i] << " "; // с помощью boolalpha выводим bool значение а не цифру
	}

	cout << endl << "\nКол-во выполненых лабораторных работ: " << get_count_completed_lab_work();
	cout << endl << "Сколько осталось сдать отчетов: " << count_false_otchets << endl;
	cout << "\n\nОценка по дисциплине: " << get_evaluation_dissepline() << endl;
}

// Метод установки сдан ли отчет по конкрутной лабораторной работе или нет или нет 
void Student_Lab_Work::set_true_otchet(int num_of_lab)
{
	check_otchet[num_of_lab] = true; // Говорим что отчет по конкретной лабе сдан и ставит ему true 
	count_false_otchets--;
}

// Метод возвращающий сколько всего отчетов надо ещё сдать
int Student_Lab_Work::get_cout_false_otchets()
{
	return count_false_otchets;
}

// Переопределенный Метод вноса информации о сданной оабораторной работе
void Student_Lab_Work::enter_info_lab(int number_lab, int estimation)
{

	// Исключеения throw
	if (number_lab > count_lab_work - 1)
	{
		throw "Номер лаборатоной не может быть больше кол-ва лаборотоных";
	}
	if (number_lab < 0)
	{
		throw "Номер лабораторной не может быть меньше 0";
	}
	if (estimation < 1)
	{
		throw "Оценка за лабораторную работу не может быть меньше 1-ого";
	}
	if (estimation > 5)
	{
		throw "Оценка за лабораторную работу не может быть больше 5-и";
	}
	if (check_otchet[number_lab] == true) // Проверяем на условие из задания, если сдан отчет оп данной лабе, то лаба сдана иначе нет
	{
		// Если принятые значения не попадают под условия исключений, то выполняется блок else
		assessment_lab_work[number_lab] = estimation; // Присваиваем заданной лабораторной работе заданную оценку
		count_completed_lab_work++; // Увеличиваем кол-во выполненых лабораторных работ
	}
	else // Если условие не выполняется просто с нашими значениями ничего не делаем
	{
		cout << "Отчет по этой лабораторной работе не сдан (" << endl;
	}
}