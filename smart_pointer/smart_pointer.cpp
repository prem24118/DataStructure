// smart_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;

class Example
{
    int x, y;
public:
    Example(int x, int y) : x(x), y(y) 
    {
        cout << "created in constructor with arguments" << endl;
    }
    Example() : x(0), y(0)
    {
        cout << "create" << endl;
    }
    ~Example()
    {
        cout << "destroyed" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    int x = 24, y = 55;
    //unique_ptr<Example> ex(new Example());
    unique_ptr<Example> example = make_unique<Example>(24, 55);

    shared_ptr<Example> shared_ex = make_shared<Example>();
    //never do this
    //shared_ptr<Example> shared_ex2(new Example());

    cout << "done";
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
