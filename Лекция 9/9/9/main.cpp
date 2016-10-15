#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
using namespace std;

bool isOK(char & c) {
	return (c >= 'A' && c <= 'Z' ||	c >= 'a' && c <= 'z');
}

string get(ifstream & in) {
	string buf = ""; 
	if (!in.good()) return "";
	char cur = (char)in.get();
	while (!isOK(cur) && in.good()) cur = (char)in.get();
	if (!isOK(cur)) return "";
	while (in.good() && isOK(cur)) {
		buf += cur;
		if (!in.good()) return buf;
		cur = (char)in.get();
		if (!isOK(cur)) return buf;
	}
	return buf;
}

void firstDifference(ifstream & in1, ifstream & in2) {
	set<string> one, two; string temp;
	while ((temp = get(in1)) != "") {
		if (!temp.empty()) one.insert(temp);
	}
	while ((temp = get(in2)) != "") {
		if (!temp.empty()) two.insert(temp);
	}
	vector<string> diff;
	set_difference(one.begin(), one.end(), two.begin(), two.end(), diff.begin());
	if (diff.size() == 0) cout << "Nothing." << endl;
	else {
		auto min = diff.begin();
		for (; min != diff.end(); min++)
			if (min -> length() != 0) break;
		if (min == diff.end()) cout << "Nothing." << endl;
		else {
			for (auto it = min; it != diff.end(); it++)
				if (*it != "") {
					if ((it -> length() < min -> length())) min = it;
				}
			//cout << *min << endl;
		}
	}
}

void secondDifference(ifstream & in1, ifstream & in2) {
	vector<set<string>> one; vector<set<string>> two; string temp; unsigned size = 0;
	while ((temp = get(in1)) != "") {
		if (!temp.empty()) {
			if (temp.length() > (size = one.size())) {
				one.resize(temp.length() + 1);
				for (unsigned i = size; i <= temp.length(); i++)
					one.emplace_back(set<string>());
			}
			one[temp.length()].emplace(temp);
		}
	}
	while ((temp = get(in2)) != "") {
		if (!temp.empty()) {
			if (temp.length() > (size = two.size())) {
				two.resize(temp.length() + 1);
				for (unsigned i = size; i <= temp.length(); i++)
					two.emplace_back(set<string>());
			}
			two[temp.length()].emplace(temp);
		}
	}
	if (one.size() == 0) { 
		//cout << "Nothing." << endl;
		return;
	}				    
	if (two.size() == 0) {
		for (auto it = one.begin(); it != one.end(); it++) {
			if ((it -> size()) != 0) {
				//cout << (*(it -> begin())) << endl;
				return;
			} 
		}
	}
	unsigned pos = 1;
	for (;;) {
		if (one.size() >= pos && two.size() >= pos) {
			if ((one[pos].size() != 0) && (two[pos].size() != 0)) {
				vector<string> diff((one[pos].size() > two[pos].size()) ? one[pos].size() : two[pos].size());
				set_difference(one[pos].begin(), one[pos].end(), two[pos].begin(), two[pos].end(), diff.begin());
				for (unsigned i = 0; i < diff.size(); i++) {
					if (diff[i] != "") {
						//cout << diff[i] << endl;
						return;
					}
				}
				pos++; continue;
			}
			if ((one[pos].size() != 0) && (two[pos].size() == 0)) {
				for (auto it = one[pos].begin(); it != one[pos].end(); it++) {
					if (*it != "") {
						//cout << *it << endl;
						return;
					}
				}
				pos++; continue;
			}
			pos++; continue;
		}
		if (one.size() >= pos && two.size() < pos) {
			if (one[pos].size() != 0) {
				for (auto it = one[pos].begin(); it != one[pos].end(); it++) {
					if (*it != "") {
						//cout << *it << endl;
						return;
					}
				}
				pos++; continue;
			}
			pos++; continue;	
		}
		if (one.size() < pos) {
			//cout << "Nothing." << endl;
			return;
		}
	}
}

int main() {
	clock_t Start = clock();
	for (int i = 0; i < 10; i++) {
		ifstream in1("first.txt"); ifstream in2("2.txt");
		firstDifference(in1, in2);
		in1.close(); in2.close();
	}
	cout << "Time Difference: " << clock() - Start << endl;
	Start = clock();
	for (int i = 0; i < 10; i++) {
		ifstream in1("first.txt"); ifstream in2("2.txt");
		secondDifference(in1, in2);
		in1.close(); in2.close();
	}
	cout << "Time Difference: " << clock() - Start << endl;
	return 0;
}