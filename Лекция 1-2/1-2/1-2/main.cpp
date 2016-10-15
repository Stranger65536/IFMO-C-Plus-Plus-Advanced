#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename T>
void print(list<T> & l) {
	list<T>::iterator it = l.begin();
	while(it != l.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

template <typename T>
void print(vector<T> & v) {
	vector<T>::iterator it = v.begin();
	while(it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

template <typename T>
void print(ofstream & out, list<T> & l) {
	list<T>::iterator it = l.begin();
	while(it != l.end()) {
		out << *it << " ";
		it++;
	}
}

bool isOne(int x) {
	return x == 1;
}

int main() {
	ifstream in("input.txt", ifstream::in);
	vector<int> v;
	v.assign(istream_iterator<int>(in), istream_iterator<int>());
	in.close(); int count = 0;
	cout << "Task 1.\nSource range: " << endl;
	print(v); 
	count = count_if(v.begin(), v.end(), [](int i){return i == 1;}); 
	cout << "There are " << count << " elements equals 1." << endl << endl;
	vector<int>::iterator it = v.begin(); list<int> l;
	while (it != v.end()) {
		if (*it != 1) l.push_back(*it);
		it++;
	}
	cout << "Task 2.\nData without elements equals 1: " << endl;
	print(l);
	in.open("input.txt", ifstream::in); v.clear(); l.clear();
	l.assign(istream_iterator<int>(in), istream_iterator<int>());
	cout << endl << "Task 3.\nSource range: " << endl;
	print(l); v.reserve(l.size());
	list<int>::iterator list_iterator = l.begin();
	for (unsigned i = 0; i < l.size(); i++) {
		v.insert(v.begin(), *list_iterator);
		list_iterator++;
	}
	cout << "Reverse range: " << endl; print(v); cout << endl;
	cout << "Task 4.\nPlease type some numbers: " << endl;
	ofstream out("output.txt", ofstream::out);
	list<int> res(20);
	merge(l.begin(), l.end(), istream_iterator<int>(cin), istream_iterator<int>(), res.begin());
	print(out, res); out.close();
	return 0;
}