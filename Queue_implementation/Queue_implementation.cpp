// Queue_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Que
{
public:
    Que()
    {
        front = -1;
        rear = -1;
        cout << "enter size";
        cin >> size;
        cout << "size" << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "i" << i << endl;
            arr[i] = 0;
            cout << "arr[i]" << arr[i] << endl;
        }

    }
    ~Que()
    {
        delete arr;
    }

    void enque(int val)
    {
        if (isFull())
        {
            cout << "queue is full";
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            //rear++;
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }

    int deque()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "no item to empty";
            return 0;
        }
        else if( front == rear)
        {
            x = arr[front];
            front = rear = -1;
        }
        else
        {
            x = arr[front];
            front++;
        }
        return x;
    }

    bool isFull()
    {
        if ((rear+1)%size == front)
        {
            return true;
        }
        else
            return false;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
            return false;
    }

    void count()
    {

    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << " " << endl;
    }
private:
    int front, rear;
    int size;
    int* arr = new int[size];
};

int main()
{
    std::cout << "Hello World!\n";
    int option, value, popped;
    Que q;
    do
    {
        cout << "\n what operation to perform" << endl;
        cout << "1. enque()" << endl;
        cout << "2. deque()" << endl;
        cout << "3. isFull()" << endl;
        cout << "4. isEmpty()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "enter value to enque" << endl;
            cin >> value;
            q.enque(value);
            break;
        case 2:
            popped = q.deque();
        case 3:
            if (q.isFull())
                cout << "q is full" << endl;
            else
                cout << "q is not full" << endl;
        case 4:
            if (q.isEmpty())
                cout << "q is empty" << endl;
            else
                cout << "q is not empty" << endl;
        case 6:
            q.display();
            break;
        }

    } while (option != 0);
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
