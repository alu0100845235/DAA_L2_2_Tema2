#ifndef HEAP
#define HEAP

#include <iostream>
#include <vector>

using namespace std;

/**
* Declaración de la clase heapSort
*/
template <class T>
class heapSort {
	public:
		heapSort();
		virtual ~heapSort();
		int sort(vector<T>& values, bool debug = false);
		int sink(int i, vector<T>& values, int size, bool debug);
		ostream& debugSwap(ostream& os, vector<T>& values, int size, int j, int k);
		ostream& debugToStudy(ostream& os, vector<T>& values, int ini, int fin, int ins);
};

/**
* Constructor vacío de la clase heapSort
*/
template <class T>
heapSort<T>::heapSort() {}

/**
* Destructor de la clase heapSort
*/
template <class T>
heapSort<T>::~heapSort() {}

/**
* Método sort que ejecuta el algoritmo heapSort
* principal. Creando el árbol, y modificandolo
* según los pasos del algoritmo
*/
template <class T>
int heapSort<T>::sort(vector<T>& values, bool debug) {
	int size = values.size();
	int steps = 0;

	for (int i = (size / 2); i > 0; --i) {
		if (debug)
			debugToStudy(cout, values, i, size - 1, 1);
		steps += sink(i, values, size, debug);
	}
	for (int i = size; i > 1; --i){
		T x = values[0];
		values[0] = values[i-1];
		values[i-1] = x;
		if (debug)
			debugToStudy(cout, values, 0, i-2, 0);
		steps += sink(1, values, i-1, debug);
	}
	if (debug)
		debugSwap(cout, values, size, -1, -1);
	return steps;
}

/**
* Método sink que se encarga de intercambiar
* los elementos necesarios a la hora de
* reorganizar el árbol
*/
template <class T>
int heapSort<T>::sink(int i, vector<T>& values, int size, bool debug) {
	int steps = 0;
	T x = values[i-1];
	int h, h1, h2;

	while ((2 * i) <= size) {
		h1 = 2 * i;
		h2 = h1 + 1;

		if (debug && h1 != size) {
			debugSwap(cout, values, size, h1-1, h2-1);
		}
		if (h1 == size)
			steps++;

		if ((h1 == size) || (values[h1-1] > values[h2-1]))
			h = h1;
		else
			h = h2;

		if (debug)
			debugSwap(cout, values, size, h-1, i-1);
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

/**
* Método que imprime los elementod del
* vector y muestra los elementos sobre
* los que se realizará el swap
*/
template <class T>
ostream& heapSort<T>::debugSwap(ostream& os, vector<T>& values, int size, int j, int k) {
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

/**
* Método que imprime los elementos del
* vector subrayando los elementos a
* "estudiar"
*/
template <class T>
ostream& heapSort<T>::debugToStudy(ostream& os, vector<T>& values, int ini, int fin, int ins) {
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
