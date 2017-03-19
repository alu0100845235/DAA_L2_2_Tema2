#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class selectionSort {
	public:
		selectionSort();
		virtual ~selectionSort();
		void swap(T& a, T& b);
		int sort(std::vector<T>& values, bool debug = false);
		ostream& debugValues(ostream& os, const std::vector<T>& values, int j, int k);
};

template<class T>
selectionSort<T>::selectionSort() {}

template <class T>
selectionSort<T>::~selectionSort() {}

template <class T>
void selectionSort<T>::swap(T& a, T& b) {
	T aux(a);
	a = b;
	b = aux;
}

template <class T>
int selectionSort<T>::sort(std::vector<T>& values, bool debug) {
	int size = values.size();
	int steps = 0;
	int i, j;

	for (i = 0; i < (size - 1); ++i) {
		for (j = (i + 1); j < size; ++j, ++steps) {
			if (debug)
				debugValues(cout, values, i, j);
			if (values[i] > values[j])
				swap(values[i], values[j]);
		}
	}
	if (debug)
		debugValues(cout, values, i, j);
	return steps;
}

template <class T>
ostream& selectionSort<T>::debugValues(ostream& os, const std::vector<T>& values, int j, int k) {
	int size = values.size();

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

#endif // SELECTIONSORT
