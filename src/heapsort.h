#ifndef HEAP
#define HEAP

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class heapSort {
	public:
		heapSort();
		virtual ~heapSort();
		int sort(vector<T>& values, bool debug = false);
		int baja(int i, vector<T>& values, int size, bool debug);
		ostream& debugValues(ostream& os, vector<T>& values, int size, int j, int k);
		ostream& debugValues2(ostream& os, vector<T>& values, int ini, int fin, int ins);
};

template <class T>
heapSort<T>::heapSort() {}

template <class T>
heapSort<T>::~heapSort() {}

template <class T>
int heapSort<T>::sort(vector<T>& values, bool debug) {
	int size = values.size();
	int steps = 0;

	for (int i = (size / 2); i > 0; --i) {
		if (debug)
			debugValues2(cout, values, i, size - 1, 1);
		steps += baja(i, values, size, debug);
	}
	for (int i = size; i > 1; --i){
		T x = values[0];
		values[0] = values[i-1];
		values[i-1] = x;
		if (debug)
			debugValues2(cout, values, 0, i-2, 0);
		steps += baja(1, values, i-1, debug);
	}
	if (debug)
		debugValues(cout, values, size, -1, -1);
	return steps;
}

template <class T>
int heapSort<T>::baja(int i, vector<T>& values, int size, bool debug) {
	int steps = 0;
	T x = values[i-1];
	int h, h1, h2;

	while ((2 * i) <= size) {
		h1 = 2 * i;
		h2 = h1 + 1;

		if (debug && h1 != size) {
			debugValues(cout, values, size, h1-1, h2-1);
		}
		if (h1 == size)
			steps++;

		if ((h1 == size) || (values[h1-1] > values[h2-1]))
			h = h1;
		else
			h = h2;

		if (debug)
			debugValues(cout, values, size, h-1, i-1);
		steps++;

		if (values[h-1] <= x)
			break;
		else {
			values[i-1] = values[h-1];
			values[h-1] = x;
			i = h;
		}
	}
	return steps;
}

template <class T>
ostream& heapSort<T>::debugValues(ostream& os, vector<T>& values, int size, int j, int k) {
	for (int i = 0; i < size; i++) {
		if ((i != j) && (i != k))
			os << values[i] << " ";
		else
			cout << "[" << values[i] << "] ";
	}
	os << endl;
	cin.ignore();
	return os;
}

template <class T>
ostream& heapSort<T>::debugValues2(ostream& os, vector<T>& values, int ini, int fin, int ins) {
	int size = values.size();

	if (ins == 1) {
		for (int i = 0; i < ini; i++)
			if (i != (ini - 1))
				cout << values[i] << " ";
			else
				cout << values[i];
		cout << " ";
	}

	cout << "\33[4m";
	for (int i = ini; i <= fin; i++)
		if (i != fin)
			cout << values[i] << " ";
		else
			cout << values[i];
	cout << "\33[0m" << " ";

	for (int i = (fin + 1); i < size; i++)
		if (i != (size - 1))
			cout << values[i] << " ";
		else
			cout << values[i];

	os << endl;
	os << endl;
	return os;
}

#endif // HEAP
