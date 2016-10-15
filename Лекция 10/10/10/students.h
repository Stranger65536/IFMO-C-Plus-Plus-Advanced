#pragma once
#include <map>
#include <vector>
using namespace std;

class Student {
	string firstName;
	string lastName;
	vector<vector<unsigned char>> rating;
public:
	Student() {
		firstName = "";
		lastName = "";
	}
	void setFirstName(const string s) {
		firstName = s;
	}
	std::string getFirstName() const {
		return firstName;
	}
	void setLastName(const string s) {
		lastName = s;
	}
	string getLastName() const {
		return lastName;
	}
	Student(const string firstName, const string lastName, const int countOfLessons) {
		this -> firstName = firstName;
		this -> lastName = lastName;
		rating.assign(countOfLessons, vector<unsigned char>());
	}
	bool isNormal() {
		return ((!lastName.empty()) && (!firstName.empty()));  
	}
	void addRate(const unsigned int pos, const unsigned char value) {
		if (pos < rating.size()) rating[pos].push_back(value);
	}
	unsigned char getRate(const unsigned lessonId, const unsigned pos) {
		if (lessonId < rating.size()) return rating[lessonId][pos];	
	}
	vector<unsigned char> getRate(const unsigned lessonId) {
		if (lessonId < rating.size()) return rating[lessonId];	
	}
};