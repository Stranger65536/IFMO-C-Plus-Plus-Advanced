#include <iostream>
#include <functional>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
struct equals : public binary_function<T, T, bool> {
	bool operator () (const T & left, const T & right) const {
		return (left == ' ' && right == ' ');
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int numbers[] = {100, 200, 300, 400};
	for (int i = 0; i < 4; i++) {
		cout << numbers[i] << " ";
	} cout << endl;
	int res[] = {0, 0, 0, 0};
	transform(numbers, numbers + 4, res, bind2nd(divides<int>(), 2));
	for (int i = 0; i < 4; i++) {
		cout << res[i] << " ";
	} cout << endl;
	ifstream in = ifstream("in.txt", ifstream::in);
	vector<char> v;
	while (in.good()) {
		v.push_back(in.get());
	}
	auto it = unique(v.begin(), v.end(), equals<char>());
	v.resize(distance(v.begin(), --it));
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it;
	}
	in.close();
	return 0;
}