#pragma once

#include<iostream>
#include<string>
#include <iomanip>

class Interface_Lab_Work // Создаем новый класс для вывода на консоль и оператора []
{

public:

	// Метод вывода информации о дисциплине и текущему состоянию её сдачи
	virtual void print_information_discipline()	 = 0; // Создаем метод с ключевым словом virtual для дальнейшего его переопределния
	virtual int& operator [](int estimation) = 0; // Создаем перегруку [] с ключевым словом virtual для дальнейшего его переопределния

	virtual ~Interface_Lab_Work() {};
};
