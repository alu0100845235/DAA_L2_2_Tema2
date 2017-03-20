#include "DataPoint.hpp"

DataPoint::DataPoint() {}

DataPoint::DataPoint(double mean, double stdDev, double median, int n):
    mean(mean),
    stdDev(stdDev),
    median(median),
    n(n)
{}

DataPoint::~DataPoint() {}

double DataPoint::getMean() const {
    return mean;
}

double DataPoint::getStdDev() const {
    return stdDev;
}

double DataPoint::getMedian() const {
    return median;
}

int DataPoint::getN() const {
    return n;
}

void DataPoint::setMean(double mean) {
    this->mean = mean;
}

void DataPoint::setStdDev(double stdDev) {
    this->stdDev = stdDev;
}

void DataPoint::setMedian(double median) {
    this->median = median;
}

void DataPoint::setN(int n) {
    this->n = n;
}
