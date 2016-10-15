#include <cstdlib>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class lengthIsGreater : public binary_function <string, int, bool> {
public:
	bool operator() (string & p, unsigned x) const {
		return p.length() > x;
	}
};

int main() {
	//1
	int mas[] = {1, 2, 3, 4, 5};
	div_t res[5];
	transform(mas, mas + 5, res, bind2nd(ptr_fun<int,int,div_t>(div), 5));
	for (int i = 0; i < 5; i++) {
		cout << res[i].quot;
	}
	//2
	cout << endl;
	vector<string> v;
	v.push_back("lol");
	v.push_back("uncle");
	v.push_back("tail");												  
	auto it = remove_if(v.begin(), v.end(), bind2nd(lengthIsGreater(), 4));
	v.resize(distance(v.begin(), it));
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}