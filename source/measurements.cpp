#include <fstream>
#include "simple-time-stats/Meter.hpp"
#include "selectionsort.h"
#include "heapsort.h"

using namespace std;

const string kConfigPath = "./config";

vector<int> randomIntVector(int size);
vector<int> readFileValues();

int main(int argc, char const *argv[]) {
    vector<int> config = readFileValues();
    selectionSort<int> selection;
    heapSort<int> heap;
    Meter meter;

    readFileValues();
    std::cout << "\nSelection Sort: " << '\n';
    meter.measure(
        config[0], // Starting size
        config[1], // Ending size
        config[2], // Number of test for each n
        config[3], // n Increment
        [&selection](int n) {
            vector<int> random = randomIntVector(n);
            selection.sort(random);
    });
    meter.printToFile("../data/selectionSortTime.txt");

    std::cout << "\nHeap Sort: " << '\n';
    meter.measure(
        config[4], // Starting size
        config[5], // Ending size
        config[6], // Number of test for each n
        config[7], // n Increment
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

vector<int> readFileValues() {
    ifstream configFile(kConfigPath);
    vector<int> config;
    string line;

    if (configFile.is_open()) {
        while (getline(configFile, line)) {
            size_t found = line.find('=');
            if (found != string::npos) {
                config.push_back(stoi(line.substr(found+1)));
            }
        }
        configFile.close();
    }
    else {
        cerr << "Can't open " << kConfigPath << endl;
    }
    return config;
}
