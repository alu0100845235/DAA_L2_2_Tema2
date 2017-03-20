#include "selectionsort.h"
#include "heapsort.h"
#include <algorithm>
#include <cstring>

const int kTestSize = 10;

using namespace std;

vector<int> randomIntVector(int size);
void printVector(vector<int>& values);
void selectionSortExample(bool debug);
void heapSortExample(bool debug);
ostream& operator<<(ostream &os, const vector<int>& values);

int main(int argc, char* const argv[]) {
    bool debug = (argc > 1) && (strcmp(argv[1], "debug") == 0);
    selectionSortExample(debug);
    heapSortExample(debug);
    return 0;
}

void selectionSortExample(bool debug) {
    vector<int> random = randomIntVector(kTestSize);
    selectionSort<int> selection;

    cout << "Selection Sort:\n";
    cout << "Input vector is:  " << random << "\n";
    selection.sort(random, debug);
    cout << "Output vector is: " << random << "\n";
}

void heapSortExample(bool debug) {
    vector<int> random = randomIntVector(kTestSize);
    heapSort<int> heap;

    cout << "Heap Sort:\n";
    cout << "Input vector is:  " << random << "\n";
    heap.sort(random, debug);
    cout << "Output vector is: " << random << "\n";
}

vector<int> randomIntVector(int size) {
    vector<int> values;
    for (int i = 0; i < size; ++i) {
        values.push_back(i);
    }
    random_shuffle(values.begin(), values.end());
    return values;
}

ostream& operator<<(ostream &os, const vector<int>& values) {
    for (int i : values) os << i << " ";
    return os;
}
