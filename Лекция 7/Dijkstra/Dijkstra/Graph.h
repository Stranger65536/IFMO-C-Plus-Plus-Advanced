#pragma once
#include <stdexcept>
#include <iostream>
#include <random>
using namespace std;

class graph {
private:
	int ** data;
	int size;
public:
	graph(const int countOfNodes) {
		data = new int*[countOfNodes]; size = countOfNodes;
		for (int i = 0; i < countOfNodes; i++) {
			data[i] = new int[countOfNodes];
			for (int j = 0; j < countOfNodes; j++) 
				data[i][j] = 0;
		}
	}
	~graph() {
		for (int i = 0; i < size; i++) {
			delete(data[i]);
		}
		delete(data);
	}
	int getSize() const {
		return size;
	}
	void setEdge(const int idFrom, const int idTo, const int weight) {
		try {
			data[idFrom][idTo] = weight;
		} catch (...) {
			cout << "Not valid node." << endl;
		}
	}
	void removeEdge(const int idFrom, const int idTo) {
		try {
			data[idFrom][idTo] = 0;
		} catch (...) {
			cout << "Not valid node." << endl; 
		}
	}
	bool isEdge(const int idFrom, const int idTo) const {
		try {
			return (data[idFrom][idTo] != 0);
		} catch(...) {
			cout << "Not valid node." << endl;
		}
	}
	int getWeight(const int idFrom, const int idTo) const {
		try {
			return data[idFrom][idTo];
		} catch(...) {
			cout << "Not valid node." << endl;
		}
	}
	void randomDirectFill(const int minValue, const int maxValue) {
		random_device rd;
		int range = maxValue - minValue;
		for (int i = 0; i < size; i++) 
			for (int j = 0; j < i + 1, i != j; j++) {
				data[i][j] = rd() % range + minValue;
				data[j][i] = rd() % range + minValue;
			}
	}
	void randomUnDirectFill(const int minValue, const int maxValue) {
		random_device rd; int temp;
		int range = maxValue - minValue;
		for (int i = 0; i < size; i++) 
			for (int j = 0; j < i + 1, i != j; j++) {
				temp = rd() % range + minValue;
				data[i][j] = temp;
				data[j][i] = temp;
			}
	}
	void Print() const {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) 
				cout << data[i][j] << " ";
			cout << endl;
		}
	}
};