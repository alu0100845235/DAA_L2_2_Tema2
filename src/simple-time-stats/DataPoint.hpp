#ifndef DATA_POINT_HPP
#define DATA_POINT_HPP

class DataPoint {
    private:
        double mean;
        double stdDev;
        double median;
        int n;

    public:
        DataPoint();
        DataPoint(double mean, double stdDev, double median, int n);
        virtual ~DataPoint();

        double getMean() const;
        double getStdDev() const;
        double getMedian() const;
        int getN() const;
        void setMean(double mean);
        void setStdDev(double stdDev);
        void setMedian(double median);
        void setN(int N);
};

#endif
