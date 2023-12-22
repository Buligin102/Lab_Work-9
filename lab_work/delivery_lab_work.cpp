#include "delivery_lab_work.h"

// Конструктор с параметрами дисцилины и количесвтом лаб работ
delivery_lab_work::delivery_lab_work(int discipline, int count_lab_work)
{
	// Проверяем коректность введенных данных и в случае не правильности данных бросаем исключение throw
	if (count_lab_work < 1)
	{
		throw "Не корректно введено кол-во работ";
	}
	else
	{
		this->count_lab_work = count_lab_work; // Если условие не выполняется, не бросается исклчение и все идет дальше
	}
	if (discipline < 0)
	{
		throw "Такой дисциплины не может быть";
	}
	else
	{
		this->discipline = discipline;
	}

	assessment_lab_work = new int[count_lab_work]; // создаем Динамический массив для оценок за лабы
	memset(assessment_lab_work, 0, sizeof(int) * count_lab_work); // Заполняем все оценки за лабы нулями
	difficulty_work = new int[count_lab_work]; // создаем Динамический массив для каждой лабы сложность поставить
	memset(difficulty_work, 0, sizeof(int) * count_lab_work); // Заполняем нулями массив сложностей

}

// Перегрузка конструктора
// Конструктор, в который передаем дисциплину класса enum, кол-во лаборатоных работ
// и массив сложнойстей лаборатоных работ
delivery_lab_work::delivery_lab_work(int discipline, int count_lab_work, int *difficult)
{
	// Создаем исключение на кол-во лаб, и задаем условие, что бы кол-во лаб не было меньше 1
	if (count_lab_work < 1)
	{
		throw "Не корректно введено кол-во работ";
	}
	else
	{
		this->count_lab_work = count_lab_work; // Если условие не выполняется, не бросается исклчение и все идет дальше
	}
	
	// Исключение на коректность введенной дисциплины
	if (discipline < 0)
	{
		throw "Такой дисциплины не может быть";
	}
	else
	{
		this->discipline = discipline;
	}

	assessment_lab_work = new int[count_lab_work]; // создаем Динамический массив для оценок за лабы
	memset(assessment_lab_work, 0, sizeof(int) * count_lab_work); // Заполняем все оценки за лабы нулями
	difficulty_work = new int[count_lab_work]; // создаем Динамический массив для каждой лабы сложность поставить
	// Копируем переданный массив сложности лабораторных работ в массив, находящийся в классе
	for (int i = 0; i < count_lab_work; i++)
	{
		difficulty_work[i] = difficult[i];
	}
}


// Гетеры (Сетеры)

// Получаем значение кол-ва выполненых лаборотоных
int delivery_lab_work::get_count_completed_lab_work()
{
	return count_completed_lab_work;
}

// Получаем значение кол-ва всего лабораторных работ
int delivery_lab_work::get_count_lab_work()
{
	return count_lab_work;
}

// Получаем значение оценки за дисциплину
float delivery_lab_work::get_evaluation_dissepline()
{
	float sum_estimation = 0; // Переменная для подсчета суммы всемх оценок
	
	// Цикл для посчета суммы всех оценк
	for (int i = 0; i < count_lab_work; i++)
	{
		sum_estimation += assessment_lab_work[i];
	}

	evaluation_dissepline = sum_estimation / count_lab_work; // Находим среднюю оценку для дисциплины

	return evaluation_dissepline;
}


// Метод вывода информации о дисциплине и текущему состоянию её сдачи
void delivery_lab_work::print_information_discipline()
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

	cout << endl << "Кол-во выполненых лабораторных работ: " << count_completed_lab_work << endl;
	cout << "Оценка по дисциплине: " << get_evaluation_dissepline() << endl;
}


// Метод вноса информации о сданной оабораторной работе
void delivery_lab_work::enter_info_lab(int number_lab, int estimation)
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
	else
	{
		// Если принятые значения не попадают под условия исключений, то выполняется блок else
		assessment_lab_work[number_lab] = estimation; // Присваиваем заданной лабораторной работе заданную оценку
		count_completed_lab_work++; // Увеличиваем кол-во выполненых лабораторных работ
	}
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const delivery_lab_work& ourObject)
{
	// Вывод дисциплины
	out << std::endl << "Дисциплина: " << ourObject.discipline;
	// Выводим номер лабораторной раоты
	out << std::endl << "Лабораторная работа: \t";
	for (int i = 0; i < ourObject.count_lab_work; i++)
	{
		out << "№" << i + 1 << " ";
	}

	// Выводим сложность под каждым номером работы
	out << std::endl << "Сложность лабораторных: ";
	for (int i = 0; i < ourObject.count_lab_work; i++)
	{
		out << ourObject.difficulty_work[i] << "  ";
	}

	// Выводим оценки под каждой дисциплиной
	out << std::endl << "Оцнека лабораторной: \t";
	for (int i = 0; i < ourObject.count_lab_work; i++)
	{
		out << ourObject.assessment_lab_work[i] << "  ";
	}

	return out; // Возращаем все то что выводили out
}
// Перегрузка оператора [] для вноса оценки, полученной при сдаче лаб работы
int& delivery_lab_work::operator [](int num_lab)
{
	return assessment_lab_work[num_lab]; // устанавливваем и возвращаем введенную оценку
}

// Перегрузка оператора += для расчета кол-ва несданных работ по дисциплине
void operator +=(int& sum, delivery_lab_work& ourObject)
{
	for (int i = 0; i < ourObject.count_lab_work; i++)
	{
		if (ourObject.assessment_lab_work[i] == 0) // Если оценка равна 0, то мы считаем ее как не сданную
		{
			sum += 1; 
		}
	}
}
