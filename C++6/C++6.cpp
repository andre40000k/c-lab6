#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <vector>

using namespace std;

struct Student
{
	string name;
	string group;
	int bal[3];
	int grant;
};

void Input(Student* student, int n)
{
	for(int i = 0; i<n;i++)
	{
		cout << endl << "name: ";
		cin >> student[i].name;

		cout << endl << "group: ";
		cin >> student[i].group;
				
		cout << endl << "bal1: ";
		cin >> student[i].bal[0];

		cout << endl << "bal2: ";
		cin >> student[i].bal[1];

		cout << endl << "bal3: ";
		cin >> student[i].bal[2];

		cout << endl << "stipuha: ";
		cin >> student[i].grant;
		cout << endl;
	}	
}

void zapis(Student* student, int n)
{
	string Name = "Binarfile.bin";
	ofstream name;
	name.open(Name, ios::binary );
	for (int i = 0; i < n; i++)
	{
		name.write((char*)(&student[i]), sizeof(Student));
	}
	name.close();
}

void vuvod(Student STUDENT/*, int n*/)
{	
	string Name = "Binarfile.bin";
	ifstream name;
	name.open(Name, ios::binary);
   while(!name.eof())
   {
	   name.read(reinterpret_cast<char*> (&STUDENT), sizeof(Student));
	   cout << "Имя: " << STUDENT.name << endl << "Група: " << STUDENT.group << endl << "Вышмат: " << STUDENT.bal[0] << endl << "Програмирование: " << STUDENT.bal[1] << endl << "ППП: " << STUDENT.bal[2] << endl;
		if (STUDENT.bal[0] < 3 || STUDENT.bal[1] < 3 || STUDENT.bal[2] < 3)
		{
			cout << "Стипендия: " << STUDENT.grant * 0.8 << endl << endl;
		}
		else
		{
			cout << "Стипендия: " << STUDENT.grant << endl << endl;
		}
   }	 
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, k;
	start:
	cout << "1 - Ввести и получить данные\n2 - Посмотреть исходныеданные\n3 - Ввести данные\n0 - Выход" << endl;
	cin >> k;
	switch (k)
	{
		case(1):
		{
			cout << "Сколько человек: ";
			cin >> n;
			Student* student = new Student[n];			
			Input(student, n);			
			zapis(student, n);
			Student STUDENT;
			vuvod(STUDENT);
			goto start;
			break;
		}
		case(2):
		{
			Student STUDENT;
			vuvod(STUDENT);
			goto start;
			break;
		}
		case(3):
		{
			cout << "Сколько человек: ";
			cin >> n;
			Student* student = new Student[n];
			Input(student, n);
			zapis(student, n);
			goto start;
			break;
		}
		default:
			break;
	}	
	return 0;
}
