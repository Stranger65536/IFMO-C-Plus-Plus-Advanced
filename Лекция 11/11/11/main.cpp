#include <exception>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

class StackEmptyException : public exception {
public:
	string what() {
		return "Stack is empty";
	};
};

class MemoryAllocationException : public exception {
public:
	string what() {
		return "Can't allocate memory";
	};
};

class MemoryReallocationException : public exception {
public:
	string what() {
		return "Can't reallocate memory";
	};
};

template <typename T>
class Stack {
public:
	class Iterator: public std::iterator <std::random_access_iterator_tag, T> {
	public:
		typedef random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef int difference_type;
		typedef int distance_type;	
		typedef T* pointer;
		typedef T& reference;
	private:
		pointer ptr;
	public:
		//constructors
		Iterator() {
			ptr = NULL;
		}
		Iterator(pointer p) {
			ptr = p;
		}
		//bool
		bool operator == (const Iterator & right) const {
			return this -> ptr == right.ptr;
		}
		bool operator != (const Iterator & right) const {
			return this -> ptr != right.ptr;
		}
		bool operator <= (const Iterator & right) const {
			return this -> ptr <= right.ptr;
		}
		bool operator >= (const Iterator & right) const {
			return this -> ptr >= right.ptr;
		}
		bool operator < (const Iterator & right) const {
			return this -> ptr < right.ptr;
		}
		bool operator > (const Iterator & right) const {
			return this -> ptr > right.ptr;
		}
		//spec
		pointer operator -> () const {
			return ptr;
		}
		reference operator * () const {
			return *ptr;
		}
		reference operator [] (int value) {
			return *(ptr + value);
		}
		//=
		Iterator & operator = (const Iterator & right) {
			this -> ptr = right.ptr;
			return *this;
		}
		Iterator & operator = (const pointer right) {
			this -> ptr = right;
			return *this;
		}
		//binary + -
		friend const Iterator operator + (const Iterator & left, const int & right) {
			return Iterator(left.ptr + right);
		}
		friend const int operator - (const Iterator & left, const Iterator & right) {
			return left.ptr - right.ptr;
		}
		friend const Iterator operator - (const Iterator & left, const int & right) {
			return Iterator(left.ptr - right);
		}
		//unary ++ --
		friend const Iterator & operator ++ (Iterator & curr) {
			curr.ptr++;
			return curr;
		}
		friend const Iterator operator ++ (Iterator & curr, int) {
			Iterator old = Iterator(curr);
			curr.ptr++;
			return old;
		}
	    friend const Iterator & operator -- (Iterator & curr) {
			curr.ptr--;
			return curr;
		}
		friend const Iterator operator -- (Iterator & curr, int) {
			Iterator old = Iterator(curr);
			curr.ptr--;
			return old;
		}
		//binary += -=
		Iterator & operator += (const int & right) {
			this -> ptr += right;
			return *this;
		}
		Iterator & operator -= (const int & right) {
			this -> ptr -= right;
			return *this;
		}
	};
private:
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	Iterator begin, end;
	pointer data;
	unsigned capacity;
	unsigned size;
private:
	pointer allocate() {
		pointer location = new (nothrow) value_type[capacity];
		if (data == NULL) throw MemoryAllocationException();
		return location;
	}
	pointer reallocate() {
		pointer newLocation = static_cast<pointer>(realloc(data, capacity));
		if (newLocation == NULL) throw MemoryReallocationException();
		return newLocation;
	}
public:
	Stack() {
		size = 0;
		capacity = 10;
		begin = NULL;
		end = NULL;
		try {
			data = allocate();
			begin = data;
			end = data;
		} catch(MemoryAllocationException & e) {
			cout << e.what() << endl;
		}
	}
	Stack(unsigned capacity) {
		size = 0;
		(this -> capacity) = 10;
		begin = (int*)(NULL);
		end = (int*)NULL;
		try {
			data = allocate();
			begin = data;
			end = data;
		} catch(MemoryAllocationException & e) {
			cout << e.what() << endl;
		}
	}
	int push(value_type value) {
		if (size != capacity) {
			data[size++] = value;
			end++;
			return 0;
		} else {
			try {
				capacity *= 2;
				data = reallocate();
				begin = data;
				end = data + size;
			} catch (MemoryReallocationException & e) {
				cout << e.what() << endl;
				capacity /= 2;
				return -1;
			}
			data[size++] = value;
			end++;
			return 0;
		}
	}
	value_type pop() {
		if (size == 0)
			throw StackEmptyException();
		value_type temp = data[--size]; end--;
		return temp;
	}
	Iterator Begin() const {
		return begin;
	}
	Iterator End() const {
		return end;
	}
	~Stack() {
		delete[] data;
	}
};

int main() {
	Stack<int> s(4);
	for (int i = 0; i < 9; i++) {
		int res = s.push(i);
		if (res == 0) cout << i << " added" << endl;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		try {
			cout << s.pop() << " removed" << endl;
		} catch (StackEmptyException & e) {
			cout << e.what() << endl;
		}
	}
	cout << endl;
	cout << "distance: " << s.End() - s.Begin() << endl;
	Stack<int>::Iterator it = s.Begin();
	cout << "random access: " << it[0] << " " << *(it + 1) << " ";
	it = it + 2; cout << *it << " ";
	cout << *(it += 1) << endl;
	sort(s.Begin(), s.End(), greater<int>());
	cout << endl;
	for (Stack<int>::Iterator it = s.Begin(); it != s.End(); it++) {
		cout << *it << " ";
	}
	return 0;
}