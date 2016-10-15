#pragma once
#include <vector>
#include <string>
using namespace std;

class Lessons {
private:
	vector<string> data;
public:
	Lessons() {
	}
	void add(const string s) {
		if (s.compare("") != 0)
			if (find(data.begin(), data.end(), s) == data.end())
				data.push_back(s);
	}
	unsigned count() const {
		return data.size();
	}
	string get(const unsigned i) const {
		if (i < data.size()) return data[i];
		else return "";
	}
	int getId(const string s) const {
		if (s.compare("")) return -1;
		unsigned temp = distance(data.begin(), find(data.begin(), data.end(), s)); 
		if (temp != data.size()) return temp;
		else return -1;
	}
	void remove(unsigned i) {
		if (i < data.size()) data.erase(data.begin() + i);
	}
	void remove(const string s) {
		vector<string>::iterator it;
		if ((it = find(data.begin(), data.end(), s)) != data.end()) data.erase(it);
	}
};