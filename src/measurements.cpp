#include "simple-time-stats/Meter.hpp"
#include "selectionsort.h"
#include "heapsort.h"

using namespace std;

vector<int> randomIntVector(int size);

int main(int argc, char const *argv[]) {
    selectionSort<int> selection;
    heapSort<int> heap;
    Meter meter;

    meter.measure(
        10000, // Starting size
        30000, // Ending size
        8,     // Number of test for each n
        2000,  // n Increment
        [&selection](int n) {
            vector<int> random = randomIntVector(n);
            selection.sort(random);
    });
    meter.printToFile("selectionSortTime.txt");

    meter.measure(
        10000000, // Starting size
        30000000, // Ending size
        8,        // Number of test for each n
        2000000,  // n Increment
        [&heap](int n) {
            vector<int> random = randomIntVector(n);
            heap.sort(random);
    });
    meter.printToFile("heapSortTime");

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
