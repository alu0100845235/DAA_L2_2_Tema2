#include "selectionsort.h"
#include <algorithm>

const int kTestSize = 10;

using namespace std;

vector<int> randomIntVector(int size);
void printVector(vector<int>& values);
void selectionSortExample();
ostream& operator<<(ostream &os, const vector<int>& values);

int main(int argc, char* argv[]) {
    selectionSortExample();
    return 0;
}

void selectionSortExample() {
    vector<int> random = randomIntVector(kTestSize);
    selectionSort<int> selection;

    cout << "Selection Sort:\n";
    cout << "Input vector is:  " << random << "\n";
    selection.sort(random);
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
