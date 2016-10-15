#pragma once
#include <iostream>
#include <string>
#include <vector>

class Student {
private:
	unsigned id;
	std::string firstName;
	std::string lastName;
	std::vector<unsigned char> rating;
public:
	Student() {
		id = 0;
		firstName = "";
		lastName = "";
	}
	void setFirstName(const std::string s) {
		firstName = s;
	}
	std::string getFirstName() {
		return firstName;
	}
	void setLastName(const std::string s) {
		lastName = s;
	}
	std::string getLastName() {
		return lastName;
	}
	void setId(unsigned i) {
		id = i;
	}
	unsigned getId() {
		return id;
	}
	Student(const unsigned id, const std::string firstName, const std::string lastName, const int countOfLessons) {
		this -> id = id;
		this -> firstName = firstName;
		this -> lastName = lastName;
		rating.assign(countOfLessons, 0);
	}
	bool isNormal() {
		return ((lastName != "") && (firstName != ""));  
	}
	void addRate(const unsigned char value) {
		rating.push_back(value);
	}
	void setRate(const unsigned lessonId, const unsigned char value) {
		try {
			if (lessonId < rating.size()) rating[lessonId] = value;
			else throw -1;
		} catch (int i) {
			if (i == -1) std::cout << "This lesson doesn't exist." << std::endl;
			}
	}
	unsigned char getRate(const unsigned lessonId) {
		try {
			if (lessonId < rating.size()) return rating[lessonId];
			else throw -1;
		} catch (int i) {
			if (i == -1) std::cout << "This lesson doesn't exist." << std::endl;
		} return -1;
	}
	void deleteRate(const unsigned lessonId) {
		try {
			if (lessonId < rating.size()) rating.erase(rating.begin() + lessonId);
			else throw -1;
		} catch (int i) {
			if (i == -1) std::cout << "This lesson doesn't exist." << std::endl;
		}
	}
};