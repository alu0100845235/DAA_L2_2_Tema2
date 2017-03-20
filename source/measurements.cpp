#include "simple-time-stats/Meter.hpp"
#include "selectionsort.h"
#include "heapsort.h"

using namespace std;

vector<int> randomIntVector(int size);

int main(int argc, char const *argv[]) {
    selectionSort<int> selection;
    heapSort<int> heap;
    Meter meter;

    std::cout << "\nSelection Sort: " << '\n';
    meter.measure(
        5000,   // Starting size
        100000, // Ending size
        3,      // Number of test for each n
        5000,   // n Increment
        [&selection](int n) {
            vector<int> random = randomIntVector(n);
            selection.sort(random);
    });
    meter.printToFile("../data/selectionSortTime.txt");

    std::cout << "\nHeap Sort: " << '\n';
    meter.measure(
        200000,   // Starting size
        10000000, // Ending size
        3,        // Number of test for each n
        200000,   // n Increment
        [&heap](int n) {
            vector<int> random = randomIntVector(n);
            heap.sort(random);
    });
    meter.printToFile("../data/heapSortTime.txt");

    return 0;
}

vector<int> randomIntVector(int size) {
    vector<int> values;
    for (int i = 0; i < size; ++i) {
        values.push_back(i);
    }
    random_shuffle(values.begin(), values.end());
    return values;
}
