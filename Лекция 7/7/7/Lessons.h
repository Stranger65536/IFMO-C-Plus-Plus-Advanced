#pragma once
#include <string>
#include <vector>

class Lessons {
private:
	std::vector<std::string> data;
public:
	Lessons() {
	}
	void add(std::string s) {
		if (s.compare("") != 0) {
			if (find(data.begin(), data.end(), s) == data.end()) {
				data.push_back(s);
				throw 1;
			} else throw -1;
		} else throw -2;
	}
	unsigned count() {
		return data.size();
	}
	std::string get(unsigned i) {
		if (i < data.size()) return data[i];
		else return "";
	}
	int getId(std::string s) {
		if (s.compare("")) return -1;
		unsigned temp = distance(data.begin(), find(data.begin(), data.end(), s)); 
		if (temp != data.size()) return temp;
		else return -1;
	}
	void remove(unsigned i) {
		if (i < data.size()) data.erase(data.begin() + i);
	}
	void remove(std::string s) {
		std::vector<std::string>::iterator it;
		if ((it = find(data.begin(), data.end(), s)) != data.end()) data.erase(it);
	}
};