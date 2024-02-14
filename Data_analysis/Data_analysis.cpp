// Data_analysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Analysis
{
public:
    double calcMean(const vector<double>& nums)
    {
        double mean = 0;
        for (const auto x : nums)
        {
            mean += x;
        }
        mean /= nums.size();
        return mean;
    }

    double calcMedian(const vector<double>& nums)
    {
        double median = 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if ( size % 2 == 0)
        {
            median = (nums[size / 2 - 1] + nums[size / 2]) / 2;
        }
        else
        {
            median = nums[size / 2];
        }
        return median;
    }

    double calcVariance(const vector<double>& nums, double mean)
    {
        double variance = 0;
        int size = nums.size();
        for (auto x : nums)
        {
            variance += (x - mean) * (x - mean);
        }
        variance = variance / size;
        return variance;
    }
    
    double calcStandardDeviation(double variance)
    {
        return sqrt(variance);
    }
};

int main()
{
    std::cout << "Hello World!\n";
    vector<double> nums = { 4.5, 2, 7.3, 1.8, 6.2, 3.9 };
    Analysis sol;
    int mean = 0, median = 0, variance = 0, standardDeviation = 0;
    mean = sol.calcMean(nums);
    median = sol.calcMedian(nums);
    variance = sol.calcVariance(nums, mean);
    standardDeviation = sol.calcStandardDeviation(variance);
    cout << "mean : " << mean << endl;
    cout << "median : " << median << endl;
    cout << "variance : " << variance << endl;
    cout << "standard deviation : " << standardDeviation << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
