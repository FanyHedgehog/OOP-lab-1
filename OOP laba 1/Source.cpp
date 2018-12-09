#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct Student{
	char surname[64];
	char name[64];
	int day;
	int month;
	int year;
};
struct Student2{
	char surname[64];
	char name[64];
	int day;
	int month;
	int year;
	int sex;
	int address;
	int phone_number;
	int course;
	int group;
	int session1;
	int session2;
	int session3;
	int session4;
};

void RW(Student mass[], int N);
void RW1(Student2 mass[], int N);
void RW2(Student2 mass[], int N);
void RD(Student mass[], int N);
void winter(Student mass[], int N);
void RW(Student2 mass[], int N);
void RD(Student2 mass[], int N);
void sort(Student2 mass[], int N);
void output(Student2 mass[], int N);
void main(){
	setlocale(LC_ALL, "Ukrainian");
	srand(time(NULL));
	int N;
	cout << "Введiть к-ть студентiв: N= ";
	cin >> N;
	Student *student = new Student[N];
	Student2 *student2 = new Student2[N];
	for (int i = 0; i < N; i++){
		cout << "Введiть прiзвище та iм'я" << endl;
		cin >> student[i].surname;
		strcpy(student2[i].surname, student[i].surname);
		cin >> student[i].name;
		strcpy(student2[i].name, student[i].name);
		student[i].day = 1 + rand() % 30;
		student2[i].day = student[i].day;
		student[i].month = 1 + rand() % 12;
		student2[i].month = student[i].month;
		student[i].year = 1980 + rand() % 20;
		student2[i].year = student[i].year;
		student2[i].sex = rand() % 2;
		student2[i].phone_number = rand() % 10000;
		student2[i].address = rand() % 10000;
		student2[i].course = 1 + rand() % 6;
		student2[i].group = 1 + rand() % 4;
		student2[i].session1 = 1 + rand() % 5;
		student2[i].session2 = 1 + rand() % 5;
		student2[i].session3 = 1 + rand() % 5;
		student2[i].session4 = 1 + rand() % 5;

	}
	int z; 
	cout << "Виберіть дію" << endl;
	cout << "1 Створити новий файл" << endl;
	cout << "2 дозаписати файл" << endl;
	cout << "3 Видалити вміст існуючого" << endl;
	cin >> z;
	if (z == 1){
		RW(student2, N);
	}
	else if (z == 2){
		RW1(student2, N);
	}
	else if (z == 3){
		RW2(student2, N);
	}
	Student *pupils = new Student[N];
	Student2 *pupils2 = new Student2[N];
	RD(pupils, N);
	winter(pupils, N);
	cout << endl;
	cout << endl;

	RD(pupils2, N);
	cout << endl;
	cout << "Студенти вiдсортованi за курсами" << endl;
	cout << endl;
	sort(pupils2, N);
	output(pupils2, N);
	cin.get();
	cin.get();

}
void winter(Student mass[], int N){
	cout << "Взимку родились:" << endl;
	for (int i = 0; i < N; i++)
	{
		if (mass[i].month == 12 || mass[i].month < 3){
			cout << mass[i].surname << endl;
		}
	}
}
void RW(Student mass[], int N){
	ofstream a_file("INFO.DAT", ios::app);
	for (int i = 0; i < N; i++){
		a_file.write((char *)&mass[i], sizeof(Student));
	}
	a_file.close();
}
void RD(Student mass[], int N){
	ifstream a_file("INFO.DAT");
	for (int i = 0; i < N; i++){
		a_file.read((char *)&mass[i], sizeof(Student));
		cout << "Прiзвище:" << mass[i].surname << endl;
		cout << "Iм'я:" << mass[i].name << endl;
		cout << "Дата народження:" << mass[i].day << "." << mass[i].month << "." << mass[i].year << endl;
	}
	a_file.close();
}
void sort(Student2 mass[], int N){
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (mass[i].course > mass[j].course){
				Student2 tmp = mass[j];
				mass[j] = mass[i];
				mass[i] = tmp;
			}
		}
	}
}
void RW(Student2 mass[], int N){
	ofstream a_file("INFO.txt", ios_base::out);//відкриття для запису
	for (int i = 0; i < N; i++){
		a_file << mass[i].surname << endl;
		a_file << mass[i].name << endl;
		a_file << mass[i].day << endl;
		a_file << mass[i].month << endl;
		a_file << mass[i].year << endl;
		a_file << mass[i].sex << endl;
		a_file << mass[i].address << endl;
		a_file << mass[i].phone_number << endl;
		a_file << mass[i].course << endl;
		a_file << mass[i].group << endl;
		a_file << mass[i].session1 << endl;
		a_file << mass[i].session2 << endl;
		a_file << mass[i].session3 << endl;
		a_file << mass[i].session4;
	}
	a_file.close();
}
void RW1(Student2 mass[], int N){
	ofstream a_file("INFO.txt", ios_base::app);//дозапис в кінець
	for (int i = 0; i < N; i++){
		a_file << mass[i].surname << endl;
		a_file << mass[i].name << endl;
		a_file << mass[i].day << endl;
		a_file << mass[i].month << endl;
		a_file << mass[i].year << endl;
		a_file << mass[i].sex << endl;
		a_file << mass[i].address << endl;
		a_file << mass[i].phone_number << endl;
		a_file << mass[i].course << endl;
		a_file << mass[i].group << endl;
		a_file << mass[i].session1 << endl;
		a_file << mass[i].session2 << endl;
		a_file << mass[i].session3 << endl;
		a_file << mass[i].session4;

	}
	a_file.close();
}
void RW2(Student2 mass[], int N){
	ofstream a_file("INFO.txt", ios_base::trunc);
	for (int i = 0; i < N; i++){
		a_file << mass[i].surname << endl;
		a_file << mass[i].name << endl;
		a_file << mass[i].day << endl;
		a_file << mass[i].month << endl;
		a_file << mass[i].year << endl;
		a_file << mass[i].sex << endl;
		a_file << mass[i].address << endl;
		a_file << mass[i].phone_number << endl;
		a_file << mass[i].course << endl;
		a_file << mass[i].group << endl;
		a_file << mass[i].session1 << endl;
		a_file << mass[i].session2 << endl;
		a_file << mass[i].session3 << endl;
		a_file << mass[i].session4;

	}
	a_file.close();
}
void RD(Student2 mass[], int N){
	ifstream a_file("INFO.txt");
	for (int i = 0; i < N; i++){
		a_file >> mass[i].name;
		a_file >> mass[i].surname;
		a_file >> mass[i].day;
		a_file >> mass[i].month;
		a_file >> mass[i].year;
		a_file >> mass[i].sex;
		a_file >> mass[i].address;
		a_file >> mass[i].phone_number;
		a_file >> mass[i].course;
		a_file >> mass[i].group;
		a_file >> mass[i].session1;
		a_file >> mass[i].session2;
		a_file >> mass[i].session3;
		a_file >> mass[i].session4;
	}
	cout << "Усi студенти:" << endl;
	output(mass, N);
	a_file.close();

}
void output(Student2 mass[], int N){
	for (int i = 0; i < N; i++){
		cout << "Surname: " << mass[i].surname << endl;
		cout << "Name: " << mass[i].name << endl;
		cout << "Day: " << mass[i].day << endl;
		cout << "Month: " << mass[i].month << endl;
		cout << "Year: " << mass[i].year << endl;
		if (mass[i].sex>0){
			cout << "Sex: w" << endl;
		}
		else{
			cout << "Sex: m" << endl;
		}
		cout << "Address: " << mass[i].address << endl;
		cout << "Phone: " << mass[i].phone_number << endl;
		cout << "Course: " << mass[i].course << endl;
		cout << "Group:" << mass[i].group << endl;
		cout << "Session1: " << mass[i].session1 << endl;
		cout << "Session2: " << mass[i].session2 << endl;
		cout << "Session3: " << mass[i].session3 << endl;
		cout << "Session4: " << mass[i].session4 << endl;
		cout << "_____________________" << endl;
	}
}