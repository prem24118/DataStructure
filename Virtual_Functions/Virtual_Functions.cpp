// Virtual_Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;
class base1
{
public:
    virtual void printfunc()
    {
        cout << "base1 print" << endl;
    }
};

class base2
{
public:
    virtual void printfunc()
    {
        cout << "base2 print" << endl;
    }
};
class derived1 : public base1, public base2
{
public:
    void printfunc() override
    {
        cout << "derived print" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    derived1 der;
    der.printfunc();
    cout << endl;
    unique_ptr<base2> base2obj1 = make_unique<derived1>();// (new  derived1());
    base2obj1->printfunc();
    unique_ptr<derived1> arr = make_unique<derived1>();
    arr->printfunc();
    arr->base1::printfunc();
     int x = 0;
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
