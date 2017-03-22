#include "Meter.hpp"

Meter::Meter() {}
Meter::~Meter() {}

void Meter::measure(int start, int end, int tests, int increments, std::function<void(int)> function) {
    std::vector<double> testsTime;
    std::chrono::high_resolution_clock::time_point beginTime;
    std::chrono::high_resolution_clock::time_point endTime;
    std::chrono::nanoseconds value;

    points.clear();
    for (int n = start; n < end; n += increments) {
        testsTime.clear();
        for (int test = 0; test < tests; ++test) {
            printInfo(n, start, end, test, tests);
            beginTime = std::chrono::high_resolution_clock::now();
            function(n);
            endTime = std::chrono::high_resolution_clock::now();
            value = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime);
            testsTime.push_back(value.count() * 1E-9);
        }
        points.push_back(generateDataPoint(testsTime, n));
    }
    printInfo(end, start, end, tests, tests);
}

void Meter::printInfo(int n, int start, int end, int test, int tests) const {
    double step      = (n - start) * tests + test;
    double max_steps = (end - start) * tests;
    double progress  = step / max_steps;
    std::cout <<  "\r" << progressBar(progress);
    std::cout << " " << ((int)progress * 100) << " %";
    std::cout << ", Test: " << test << "/" << tests;
    std::cout << ", Size: " << n << "/" << end;
    std::cout << ", Last mean time: " << (points.empty() ? 0 : points.back().getMean()) << "s";
    std::cout << "     " << std::flush;
}

std::string Meter::progressBar(double progress, int size) const {
    int characters = progress*size;

    std::stringstream  bar;
    bar.precision(2);
    bar << "|";
    for (int i = 0; i < characters; ++i) {
        bar << "=";
    }
    for (int i = characters; i < size; ++i) {
        bar << " ";
    }
    bar << "|";
    return bar.str();
}

void Meter::setPointMean(const std::vector<double>& values, DataPoint& point) {
    double sum = std::accumulate(std::begin(values), std::end(values), 0.0);
    point.setMean(sum / values.size());
}

void Meter::setPointStdDev(const std::vector<double>& values, DataPoint& point) {
    std::vector<double> diff(values.size());
    double mean = point.getMean();

    std::transform(values.begin(), values.end(), diff.begin(), [mean](double x) { return x - mean; });
    double sqSum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    point.setStdDev(std::sqrt(sqSum / values.size()));
}

void Meter::setPointMedian(std::vector<double>& values, DataPoint& point) {
    if(values.empty()) point.setMedian(0);

    std::sort(values.begin(), values.end());
    if(values.size() % 2)
        point.setMedian(values[values.size() / 2]);
    else
        point.setMedian((values[values.size() / 2 - 1] + values[values.size() / 2]) / 2);
}

DataPoint Meter::generateDataPoint(std::vector<double>& values, int n) {
    DataPoint point;
    setPointMean(values, point);
    setPointStdDev(values, point);
    setPointMedian(values, point);
    point.setN(n);
    return point;
}

std::ostream& Meter::print(std::ostream &os) const {
    os << "Size\tMean\tMedian\tStdDev\n";
    for (DataPoint point : points) {
        os << point.getN() << "\t";
        os << point.getMean() << "\t";
        os << point.getMedian() << "\t";
        os << point.getStdDev() << "\n";
    }
    return os;
}

void Meter::printToFile(std::string path, char separator) const {
    std::ofstream outputFile(path);
    for (DataPoint point : points) {
        outputFile << point.getN() << separator;
        outputFile << point.getMean() << separator;
        outputFile << point.getMedian() << separator;
        outputFile << point.getStdDev() << "\n";
    }
}
