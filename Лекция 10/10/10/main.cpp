#include "lessons.h"
#include "students.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;

class DataBase {
	map<unsigned, Student*> students;
	Lessons lessons;
public:
	DataBase() {
	}
	static bool cmp(Student * left, Student * right) {
		if (left -> getLastName() == right -> getLastName()) {
			return left -> getFirstName() < right -> getFirstName();
		} else return (left -> getLastName() < right -> getLastName());
	}
	void addStudent(const string FirstName, const string LastName) {
		Student * temp = new Student(FirstName, LastName, lessons.count());
		if (temp -> isNormal())	{
			students[students.size()] = temp;
			cout << FirstName << " " << LastName << " succesfully added." << endl;
		}
		else cout << "Bad Name." << endl; 
	}
	void addLesson(const string s) {
		lessons.add(s);
	}
	void addRateByLessonId(const unsigned id, const unsigned lessonId, const unsigned char rate) {
		students[id] -> addRate(lessonId, rate);
	}
	void sortStudentsAlphabetic() {
		sort(students.begin(), students.end(), cmp);
	}
	static bool cmp2(Student * left, Student * right) {
		if ((left -> getRate(id)) == (right -> getRate(id))) {
			if (left -> getLastName() == right -> getLastName()) {
				return left -> getFirstName() < right -> getFirstName(); 
			} else return (left -> getLastName() < right -> getLastName());
		} else return ((left -> getRate(id)) < (right -> getRate(id)));
	}
};

int main() {
	return 0;
}