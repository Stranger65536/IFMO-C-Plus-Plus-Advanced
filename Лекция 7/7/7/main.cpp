#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include "Student.h"
#include "Lessons.h"
using namespace std;
string firstName, lastName;
unsigned id;
class DataBase {
private:
	vector<Student*> students;
	Lessons lessons; 
public:
	static bool cmp(Student * left, Student * right) {
		if (left -> getLastName() == right -> getLastName()) {
			return left -> getFirstName() < right -> getFirstName();
		} else return (left -> getLastName() < right -> getLastName());
	}
	DataBase() {
	}
	void addStudent(const string FirstName, const string LastName) {
		Student * temp = new Student(students.size(), FirstName, LastName, lessons.count());
		if (temp -> isNormal())	{
			students.push_back(temp);
			cout << FirstName << " " << LastName << " succesfully added." << endl;
		}
		else cout << "Bad Name." << endl; 
	}
	void addLesson(const string s) {
		try {
			lessons.add(s);
		} catch(int i) {
			if (i == -1) cout << "This lesson is already there." << endl; 
			if (i == -2) cout << "Empty name." << endl;
			if (i == 1) {
				for (unsigned i = 0; i < students.size(); i++) students[i] -> addRate(0);
				cout << s << " succesfully added." << endl;
			}
		}
	}
	void setRateByLessonId(const unsigned id, const unsigned lessonId, const unsigned char rate) {
		students[id] -> setRate(lessonId, rate);
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
	void sortStudentsByRateAndAlphabetic() {
		sort(students.begin(), students.end(), cmp2);
	}
	void PrintNames() {
		for (unsigned i = 0; i < students.size(); i++) {
			string lastName = students[i] -> getLastName();
			string firstName = students[i] -> getFirstName();
			cout << i << ". " << lastName << " " << firstName << endl;
		} cout << endl;
	}
	void PrintNamesAndRateById(unsigned id) {
		for (unsigned i = 0; i < students.size(); i++) {
			string lastName = students[i] -> getLastName();
			string firstName = students[i] -> getFirstName();
			cout << i << ". " << (unsigned)(students[i] -> getRate(id)) << " " << lastName << " " << firstName << endl;
		} cout << endl;
	}
	unsigned countOfStudents() {
		return students.size();
	}
	unsigned countOfLessons() {
		return lessons.count();
	}
	void PrintAverageRateForLessons() {  
		float sum;
		for (unsigned i = 0; i < lessons.count(); i++) {
			sum = 0;
			for (unsigned j = 0; j < students.size(); j++) {
				sum += students[j] -> getRate(i);
			}
			cout << i << ". " << lessons.get(i) << ": " << sum / students.size() << endl;
		}
	}
	void PrintAverageRateForStudents() {  
		float sum;
		for (unsigned i = 0; i < students.size(); i++) {
			sum = 0;
			for (unsigned j = 0; j < lessons.count(); j++) {
				sum += students[i] -> getRate(j);
			}
			string lastName = students[i] -> getLastName();
			string firstName = students[i] -> getFirstName();
			cout << i << ". " << lastName << " " << firstName << ": " << sum / lessons.count() << endl;
		}
	}
	static bool ok(Student * i) {
		if (((i -> getFirstName()).find(firstName) != string::npos) &&
			((i -> getLastName()).find(lastName) != string::npos)) {
			return true;
		} else return false;
	} 
	void searchMatch(const string f, const string l) {
		cout << "Match students: " << endl;
		vector<Student*>::iterator it, it2;
		string firstName, lastName; 
		it = students.begin();
		do {
			it2 = find_if(it, students.end(), ok);
			if (it2 != students.end()) {
				firstName = (*it2) -> getFirstName();
				lastName = (*it2) -> getLastName();
				cout << firstName << " " << lastName << endl;
				it = it2 + 1;
			}
		} while (it2 != students.end());
		cout << "-----------------------" << endl;
	}
	float Average(Student * i) {
		float sum = 0;
		for (unsigned j = 0; j < lessons.count(); j++) {
			sum += (i -> getRate(j));
		}
		return sum / lessons.count();
	}
	void ShowStudentsWithAverageMoreThan() {
		cout << "Match students: " << endl;
		vector<Student*>::iterator it;
		string firstName, lastName; float temp;
		for (it = students.begin(); it != students.end(); it++) {
			if ((temp = Average(*it)) >= 4) {
				firstName = (*it) -> getFirstName();
				lastName = (*it) -> getLastName();
				cout << firstName << " " << lastName << " " << temp << endl;
			}
		}
		cout << "-----------------------" << endl;
	}
};

int main() {
	DataBase d;
	d.addLesson("Math");
	d.addLesson("Programming");
	d.addLesson("");
	d.addStudent("Vladislav", "Trofimov");
	d.addStudent("Nikita", "Akimov");
	d.addStudent("Mark", "Glasnev");
	d.addStudent("Nyanka", "Antonova");
	d.addStudent("Anton", "Vishnyakov");
	d.addStudent("Pavel", "Vinogradov");
	d.addStudent("Marina", "Sergeeva");
	d.addStudent("Andrey", "Shobey");
	d.addStudent("Andrey", "Shamanaev");
	d.addStudent("Kirill", "Makhonin");
	d.addStudent("Mudak", "Mylnikov");
	d.addStudent("Julia", "Plonina");
	d.addStudent("Dmitry", "Evdokimov");
	d.addStudent("Daniil", "Kochubey");
	d.addStudent("Polina", "Lappo");
	d.addStudent("Evgeny", "Nikityk");
	d.addStudent("Dmitry", "Khiznyakov");
	d.addStudent("Daniil", "Liskov");
	d.addStudent("Vladimir", "Khomich");
	d.addStudent("", "");
	//Random Fill
	for (unsigned i = 0; i < d.countOfStudents(); i++) {
		for (unsigned j = 0; j < d.countOfLessons(); j++) {
			d.setRateByLessonId(i, j, rand() % 5 + 1);
		}
	}
	d.sortStudentsAlphabetic();
	d.PrintNames();
	d.PrintAverageRateForLessons(); cout << endl;
	d.PrintAverageRateForStudents();
	cout << endl << "Please enter the first name or part of them: " << endl;
	cin >> firstName;
	if (firstName == "*") firstName = ""; 
	cout << "Please enter the last name or part of them: " << endl;
	cin >> lastName;
	if (lastName == "*") lastName = "";
	d.searchMatch(firstName, lastName);
	cout << endl << "Please enter an Id of lesson to sort by its rate: " << endl;
	do {
		cin >> id;
		if (id >= d.countOfLessons()) cout << "There is no lesson with this number. Try again." << endl;
	} while (id >= d.countOfLessons());
	d.sortStudentsByRateAndAlphabetic();
	d.PrintNamesAndRateById(id);
	d.ShowStudentsWithAverageMoreThan();
	return 0;
}