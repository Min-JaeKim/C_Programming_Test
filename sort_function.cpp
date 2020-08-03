#include <iostream>
#include <algorithm>

using namespace std;

class Student {
	public :
		string name;
		int score;
	Student (string name, int score){
		this->name = name;
		this->score = score;
	}
	bool operator < (Student &student){
		return this->score < student.score;
	}
};

int main(void){
	Student students[] = {
		Student("��",90),
		Student("��",99),
		Student("��",85),
		Student("��",44),
		Student("��",68)
	};
	sort(students, students + 5);
	for (int i = 0; i<5; i++)
	cout<<students[i].name<<' ';
	return 0; 
}
