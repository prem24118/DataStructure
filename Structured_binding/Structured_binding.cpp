// Structured_binding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tuple>


int main()
{
    std::cout << "Hello World!\n";
    std::tuple<int, std::string, double> person(42, "John Doe", 160);
    int age;
    std::string name;
    double weight;

    std::tie(age, name, weight) = person;

    std::tuple<int, std::string, double> person2(43, "Joe schmuck", 180);
    auto [age2, name2, weight2] = person2;
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
