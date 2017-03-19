#include "selectionsort.h"
#include <algorithm>

const int kTestSize = 10;

std::vector<int> randomIntVector(int size);
void printVector(std::vector<int>& values);
void selectionSortExample();
std::ostream& operator<<(std::ostream &os, const std::vector<int>& values);

int main(int argc, char* argv[]) {
    selectionSortExample();
    return 0;
}

void selectionSortExample() {
    std::vector<int> random = randomIntVector(kTestSize);
    selectionSort<int> selection;

    std::cout << "Selection Sort:\n";
    std::cout << "Input vector is:  " << random << "\n";
    selection.sort(random, true);
    std::cout << "Output vector is: " << random << "\n";
}

std::vector<int> randomIntVector(int size) {
    std::vector<int> values;
    for (int i = 0; i < size; ++i) {
        values.push_back(i);
    }
    std::random_shuffle(values.begin(), values.end());
    return values;
}

std::ostream& operator<<(std::ostream &os, const std::vector<int>& values) {
    for (int i : values) os << i << " ";
    return os;
}
