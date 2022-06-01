#include "MyForm.h"
#include <time.h>
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

int number, count = 0;

int min = 0, max = 51;

#define limit 7 //����� ������� �������

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
	number = rand() % 50 + 1; //��������� ����� �� 1 �� 50 ������������
}

System::Void ugadaichislo::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	generate_number();			//������������ �����
	count = 0;					//�������� �������
	textBox1->Text = "";		//�������� ���������
	button2->Enabled = true;	//�������� ������
	button2->Visible = true;	//�������� ������
	min = 0;					//�������� �������
	max = 51;					//�������� ��������

	label4->Text = "���������: ";
	label5->Text = "����� �����: ";
	label6->Text = "����������: ";
}

System::Void ugadaichislo::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    int urnumber;
	urnumber = Convert::ToInt32(textBox1->Text);//���������������� �����

	if (urnumber > number)			//��������� ����������������� ����� � ������������
	{
		label4->Text = "���������: ������";
		if(urnumber < max)	//�������� �� �����
			max = urnumber;
	}
	else if (urnumber < number)
	{
		label4->Text = "���������: ������";
		if (urnumber > min)
			min = urnumber;
	}
	else
	{
		label4->Text = "���������: ������";
		MessageBox::Show("�� ��������!");
	}

	count++; //������� ������� ������� ����� +1
	label5->Text = "����� �����: " + Convert::ToString(count); //����� �������� ������� ������� �����
	
	label6->Text = "����������: [" + Convert::ToString(min + 1) + "; " + Convert::ToString(max - 1) + "]"; //����� ����������

	if(count == limit) //�������� �� ����� �������
	{
		MessageBox::Show("�� ���������! ���������� ����� ���: " + Convert::ToString(number));
		button2->Enabled = false;			//���������� ������ ��� ������ �������
		button2->Visible = false;			
	}
}

System::Void ugadaichislo::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    generate_number();//��������� ����� ����� ��������� �����������
}

System::Void ugadaichislo::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit(); //�����
}
