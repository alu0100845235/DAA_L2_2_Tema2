#include "Meter.hpp"

Meter::Meter() {}
Meter::~Meter() {}

void Meter::measure(int start, int end, int tests, int increments, std::function<void(int)> function) {
    std::vector<double> testsTime;
    std::clock_t beginTime;
    std::clock_t endTime;

    points.clear();
    for (int n = start; n < end; n += increments) {
        testsTime.clear();
        std::cout <<  "\r" << progressBar(start, end, n) << std::flush;
        for (int test = 0; test < tests; ++test) {
            beginTime = std::clock();
            function(n);
            endTime = std::clock();
            testsTime.push_back(double(endTime - beginTime) / CLOCKS_PER_SEC);
        }
        points.push_back(generateDataPoint(testsTime, n));
    }
}

std::string Meter::progressBar(double min, double max, double current, int size) const {
    double progress = (current - min) / (max - min);
    int maxChars = progress*size;

    std::string bar = "|";
    for (int i = 0; i < maxChars; ++i) {
        bar += "=";
    }
    for (int i = maxChars; i < size; ++i) {
        bar += " ";
    }
    return bar + "|";
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
    os << "Mean\tMedian\tStdDev\n";
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
