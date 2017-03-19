#ifndef METER_HPP
#define METER_HPP

#include <vector>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <string>
#include <functional>
#include <iostream>
#include <fstream>
#include "DataPoint.hpp"

class Meter {
    private:
        std::vector<DataPoint> points;

    public:
        Meter();
        virtual ~Meter();
        void measure(int start, int end, int tests, int increments, std::function<void(int)> function);
        std::ostream& print(std::ostream &os = std::cout) const;
        void printToFile(std::string name, char separator = ',') const;

    private:
        std::string progressBar(double min, double max, double current, int size = 80) const;
        void setPointMean(const std::vector<double>& values, DataPoint& point);
        void setPointStdDev(const std::vector<double>& values, DataPoint& point);
        void setPointMedian(std::vector<double>& values, DataPoint& point);
        DataPoint generateDataPoint(std::vector<double>& values, int n);
};

#endif