// First_28.05.18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>

using namespace std;

class Person
{
protected:
	char EGN[11];
	char Name[50];
	int Age;
public:
	Person(){ EGN[0] = 0; Name[0] = 0; Age = 0; }
	Person(char *EGNInit, char *NameInit, int AgeInit);
	~Person();
	virtual int ReturnAge();
	virtual void Print();
};

class Student : public Person
{
//public:
	char FakNo[10];
	char Department[20];
	char Subject[20];
	float AvgNote;
public:
	Student() { FakNo[0] = 0;  Department[0] = 0; Subject[0] = 0; AvgNote = 0; }
	Student(char *EGNInit, char *NameInit, int AgeInit, char *FakNoInit, char *DepartmentInit, char *SubjectInit, float AvgNoteInit);
	Student(Student &St);
	~Student();
	int ReturnAge();
	void Print();
};

class Professor : public Person
{
//public:
	char Department[20];
	char Subject[20];
public:
	Professor() { Department[0] = 0; Subject[0] = 0; }
	Professor(char *EGNInit, char *NameInit, int AgeInit, char *DepartmentInit, char *SubjectInit);
	Professor(Professor &Pr);
	~Professor();
	Professor &operator =(Student &St);
	int ReturnAge();
	void Print();
};

Person::Person(char *EGNInit, char *NameInit, int AgeInit)
{
	strcpy_s(EGN, EGNInit);
	strcpy_s(Name, NameInit);
	Age = AgeInit;
}

Person::~Person()
{

}

int Person::ReturnAge()
{
	return Age;
}

void Person::Print()
{
	
}

Professor::Professor(char *EGNInit, char *NameInit, int AgeInit, char *DepartmentInit, char *SubjectInit) : Person(EGNInit, NameInit, AgeInit)
{
	strcpy_s(Department, DepartmentInit);
	strcpy_s(Subject, SubjectInit);
}

Professor::Professor(Professor &Pr)
{
	strcpy_s(EGN, Pr.EGN);
	strcpy_s(Name, Pr.Name);
	Age = Pr.Age;
	strcpy_s(Department, Pr.Department);
	strcpy_s(Subject, Pr.Subject);
}

Professor::~Professor()
{

}

/*Professor &Professor::operator=(Student &St)
{
strcpy_s(EGN, St.EGN);
strcpy_s(Name, St.Name);
Age = St.Age;
strcpy_s(Department, St.Department);
strcpy_s(Subject, St.Subject);
return *this;
}
*/

int Professor::ReturnAge()
{
	return Age;
}

void Professor::Print()
{
	cout << EGN << "\t" << Name << "\t" << Age << "\t" << Department << "\t" << Subject << endl;
}

Student::Student(char *EGNInit, char *NameInit, int AgeInit, char *FakNoInit, char *DepartmentInit, char *SubjectInit, float AvgNoteInit) : Person(EGNInit, NameInit, AgeInit)
{
	strcpy_s(FakNo, FakNoInit);
	strcpy_s(Department, DepartmentInit);
	strcpy_s(Subject, SubjectInit);
	AvgNote = AvgNoteInit;
}

Student::Student(Student &St)
{
	strcpy_s(EGN, St.EGN);
	strcpy_s(Name, St.Name);
	Age = St.Age;
	strcpy_s(FakNo, St.FakNo);
	strcpy_s(Department, St.Department);
	strcpy_s(Subject, St.Subject);
	AvgNote = St.AvgNote;
}

Student::~Student()
{

}

int Student::ReturnAge()
{
	return Age;
}

void Student::Print()
{
	cout << EGN << "\t" << Name << "\t" << Age << "\t" << FakNo << "\t" << Department << "\t" << Subject << "\t" << AvgNote << endl;
}

int Difference(Person *ptr, Person *str)
{
	if (ptr->ReturnAge() >= str->ReturnAge())
		return ptr->ReturnAge() - str->ReturnAge();
	else
		return str->ReturnAge() - ptr->ReturnAge();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Person *Pr = new Person;

	Professor Muncho("3547628", "Muncho Ivanov", 45, "KST", "MPS");
	Student Suljo("5232834", "Suljo Peshov", 20, "34567", "KST", "OOP", 5.67);

	Muncho.Print();
	Suljo.Print();
	cout << endl;

	//Muncho = Suljo;
	//Muncho.Print();
	//cout << endl;

	int d = Difference(&Muncho, &Suljo);
	cout << d << endl;
	cout << endl;
	return 0;
}

