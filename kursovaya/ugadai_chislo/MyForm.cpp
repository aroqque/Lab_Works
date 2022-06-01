#include "MyForm.h"
#include <time.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

int number, count = 0;

int min = 0, max = 51;

#define limit 7 //лимит попыток угадать

void main()
{
    srand(time(NULL));

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    ugadaichislo::MyForm form;
    Application::Run(% form);
}

void generate_number()
{
	number = rand() % 50 + 1; //Генерация числа от 1 до 50 включительно
}

System::Void ugadaichislo::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	generate_number();			//Генерировать число
	count = 0;					//Очистить счётчик
	textBox1->Text = "";		//Очистить текстбокс
	button2->Enabled = true;	//Включить кнопку
	button2->Visible = true;	//Показать кнопку
	min = 0;					//Обнулить минимум
	max = 51;					//Обнулить максимум

	label4->Text = "Результат: ";
	label5->Text = "Число ходов: ";
	label6->Text = "Промежуток: ";
}

System::Void ugadaichislo::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    int urnumber;
	urnumber = Convert::ToInt32(textBox1->Text);//пользовательское число

	if (urnumber > number)			//Сравнение пользовательского числа с генерируемым
	{
		label4->Text = "Результат: Меньше";
		if(urnumber < max)	//Проверка на гения
			max = urnumber;
	}
	else if (urnumber < number)
	{
		label4->Text = "Результат: Больше";
		if (urnumber > min)
			min = urnumber;
	}
	else
	{
		label4->Text = "Результат: Угадал";
		MessageBox::Show("Вы выиграли!");
	}

	count++; //Счётчик попыток угадать число +1
	label5->Text = "Число ходов: " + Convert::ToString(count); //Вывод счётчика попыток угадать число
	
	label6->Text = "Промежуток: [" + Convert::ToString(min + 1) + "; " + Convert::ToString(max - 1) + "]"; //Вывод промежутка

	if(count == limit) //Проверка на лимит попыток
	{
		MessageBox::Show("Вы проиграли! Правильный ответ был: " + Convert::ToString(number));
		button2->Enabled = false;			//Отключение кнопки при лимите попыток
		button2->Visible = false;			
	}
}

System::Void ugadaichislo::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    generate_number();//Генерация сразу когда программа запускается
}

System::Void ugadaichislo::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit(); //Выход
}
