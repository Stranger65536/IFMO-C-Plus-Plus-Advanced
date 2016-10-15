#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct vehile {
	double position;
	double speed;
	char number[9];
	double finish;
};

string number;
unsigned time;

bool isEqual(const vehile * i) {
	if (strcmp(i -> number, number.c_str()) == 0) return true;
	else return false;
}

bool is78(const vehile * i) {
	return ((i -> number[7] == '8') && (i -> number[6] == '7'));
}

bool cmp(const vehile * left, const vehile * right) {
	return (left -> speed < right -> speed);
}

double toFinish(const vehile * i) {
	return i -> finish - i -> position - i -> speed * time;
}

bool compare(const vehile * left, const vehile * right) {
	return (toFinish(left) < toFinish(right));
}

class fib {
public:
	vector<unsigned> operator()(const int count) {
		vector<unsigned> f;
		if (count <= 0) return f;
		if (count == 1) {
			f.push_back(0);
			return f;
		} 
		if (count >= 2) {
			int i = 2; unsigned c;
			f.push_back(0); unsigned a = 0;
			f.push_back(1); unsigned b = 1;
			while (i < count) {
				c = a + b; f.push_back(c);
				a = b; b = c; i++;
			}
			return f;
		}
	}
};

class even {
public:
	vector<unsigned> operator()(const int count) {
		vector<unsigned> f;
		if (count <= 0) return f;
		else {
			for (int a = 0, i = 0; i < count; a += 2, i++) {
				f.push_back(a);
			}
			return f;
		}
	}
};

int main() {
	//position (km)
	//speed (km per second)
	//gov. number
	//finish position (km)
	ifstream in("input.txt", ifstream::in);
	int n; in >> n; vector<vehile*> v; 
	for (int i = 0; i < n; i++) {
		vehile * temp = new vehile; 
		in >> temp -> position;
		in >> temp -> speed;
		in >> temp -> number;
		in >> temp -> finish;
		v.push_back(temp);
	}
	cout << "Problem 1. Information about vehiles read succesfully." << endl << endl;
	vector<vehile*> res;
	for (vector<vehile*>::iterator it = v.begin(); it != v.end(); it++) {
		if (is78(*it)) res.push_back(*it);
	}
	sort(res.begin(), res.end(), cmp);
	cout << "Problem 2. Sorted list with only 78 region numbers:" << endl; 
	for (vector<vehile*>::iterator it = res.begin(); it != res.end(); it++) {
		cout << (*it) -> number << " " << (*it) -> speed << endl;
	}
	cout << endl;
	cout << "Problem 3. Please enter a number to search:" << endl;
	cin >> number;
	vector<vehile*>::iterator it = find_if(v.begin(), v.end(), isEqual);
	cout << ((it == v.end()) ? "There is no vehile with this number on a road." : "Vehile with this number is on a road.") << endl << endl;
	cout << "Problem 4. Please enter a time in seconds:" << endl;
	cin >> number; time = atoi(number.c_str());
	sort(v.begin(), v.end(), compare);
	for (vector<vehile*>::iterator it = v.begin(); it != v.end(); it++) {
		double finish = toFinish(*it);
		cout << (*it) -> number << " ";
		(finish > 0) ? cout << finish << "." : cout << "Finished."; cout << endl;
		free(*it);
	}
	v.clear(); res.clear();
	cout << endl;
	cout << "Problem 5." << endl;
	fib fibFunctor; even evenFunctor;
	vector<unsigned> f = fibFunctor(20);
	vector<unsigned> e = evenFunctor(50);
	vector<unsigned> u; set_union(f.begin(), f.end(), e.begin(), e.end(), back_inserter(u));
	cout << "Union: ";
	for (vector<unsigned>::iterator it = u.begin(); it != u.end(); it++) {
		cout << *it << " ";
	} cout << endl << endl; u.clear();
	vector<unsigned> i; set_intersection(f.begin(), f.end(), e.begin(), e.end(), back_inserter(i));
	cout << "Intersection: ";
	for (vector<unsigned>::iterator it = i.begin(); it != i.end(); it++) {
		cout << *it << " ";
	} cout << endl << endl; i.clear();
	vector<unsigned> d; set_difference(f.begin(), f.end(), e.begin(), e.end(), back_inserter(d));
	cout << "Difference: ";
	for (vector<unsigned>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	} cout << endl << endl; d.clear();
}