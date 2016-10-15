#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T, typename type>
void insertSort(T begin, T end, bool (*funct)(const type & a, const type & b)) {
	unsigned size; if ((size = distance(begin, end)) <= 1) return;
	T in; T out; T temp; type left, right, value; unsigned i, j;
	for (i = 1, in = ++begin; i < size; i++, in++) {
		for (j = i, out = in; j > 0; j--, out--) {
			left = *(--out); right = *(++out);
			if ((*funct)(left, right)) {
				temp = --out; out++;
				value = *temp;	
				*temp = *out; 
				*out = value;
			}
		}
	}
}

struct Vector {
	int x;
	int y;
};

bool cmp1(const int & left, const int & right) {
	return (left > right);
}

bool cmp2(const Vector & left, const Vector & right) {
	return (left.x * left.x + left.y * left.y > right.x * right.x + right.y * right.y);
}

int main() {
	//part of array
	int a[] = {3, 1, 4, 1, 5, 9};
	insertSort<int*, int>(a, a + 4, cmp1);
	for (int i = 0; i < 6; i++) cout << a[i] << " "; cout << endl;
	//list
	list<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(1);
	v.push_back(5);
	v.push_back(9);
	insertSort<list<int>::iterator, int>(v.begin(), v.end(), cmp1);
	for (list<int>::iterator it = v.begin(); it != v.end(); it++) cout << *it << " "; cout << endl;
	//vector...it must works 'cause it works with a list, but uncle Tail said that we must do a universal function;)
	vector<Vector> l; Vector * temp = new Vector[5];
	temp[0].x = 1; temp[0].y = 1;  l.push_back(temp[0]);//2
	temp[1].x = 1; temp[1].y = 2;  l.push_back(temp[1]);//5
	temp[2].x = 5; temp[2].y = 10; l.push_back(temp[2]);//125
	temp[3].x = 1; temp[3].y = 0;  l.push_back(temp[3]);//1
	temp[4].x = 0; temp[4].y = 0;  l.push_back(temp[4]);//0
	insertSort<vector<Vector>::iterator, Vector>(l.begin(), l.end(), cmp2);
	for (vector<Vector>::iterator it = l.begin(); it != l.end(); it++) cout << (it -> x) * (it -> x) + (it -> y) * (it -> y)  << " ";
	return 0;
}

int * const p; 
