// key_value_store.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

// 
class Transaction {
public:
    unordered_map<string, string> store;
    Transaction* next;
    Transaction() : next(nullptr)  {}
    ~Transaction() {};
};

class TransactionStack {
public:
    Transaction* top;
    int size;
    TransactionStack() : top(nullptr), size(0) {}
    ~TransactionStack() {};
};

class KeyValueStoreWithTransaction {
public:
    void Begin() {
        Transaction* temp = new Transaction();
        temp->next = ts.top;
        ts.top = temp;
        ts.size++;
    }
    void End() {
        if (ts.top) {
            Transaction* node = ts.top;
            ts.top = node->next;
            node->next = nullptr;
            ts.size--;
            delete node;
        }
    }

    Transaction* Peek() {
        return ts.top;
    }

    void Commit() {
        Transaction* active = Peek();
        if (active) {
            for (auto& it : active->store) {
                auto key = it.first, value = it.second;
                globalStore[key] = value;
                if (active->next) {
                    active->next->store[key] = value;
                }
            }
        }
    }

    void Rollback() {
        if (ts.top) {
            ts.top->store.clear();
        }
    }

    void Get(string key) {
        Transaction* active = Peek();
        if (!active) {
            if (globalStore.count(key)) {
                cout << globalStore[key] << "\n";
            }
            else {
                cout << "not set\n";
            }
        }
        else {
            if (active->store.count(key)) {
                cout << active->store[key] << "\n";
            }
            else {
                cout << "not set\n";
            }
        }
    }

    void Set(string key, string value) {
        Transaction* active = Peek();
        if (!active) {
            globalStore[key] = value;
        }
        else {
            active->store[key] = value;
        }
    }

    void Delete(string key) {
        Transaction* active = Peek();
        if (!active) {
            if (globalStore.count(key)) {
                globalStore.erase(key);
            }
        }
        else {
            if (active->store.count(key)) {
                active->store.erase(key);
            }
        }
    }
private:
    TransactionStack ts;
    unordered_map<string, string> globalStore;
};

class Transaction1
{
public:
    unordered_map<string, string> store;
    Transaction1* next;
    Transaction1() : next(nullptr) {}
    ~Transaction1() {}
};

class TransactionStack1
{
public:
    Transaction1* top;
    int size;
    TransactionStack1() : top(nullptr), size(0) {}
    ~TransactionStack1() {}
};

class keyValueStore
{
private:
    unordered_map<string, string> globalStore;
    TransactionStack1 ts;
public:
    void begin()
    {
        Transaction1* temp = new Transaction1();
        temp->next = ts.top;
        ts.top = temp;
        ts.size++;
    }
    void end()
    {
        Transaction1* node = ts.top;
        ts.top = node->next;
        node->next = nullptr;
        ts.size--;
        delete node;
    }
    Transaction1* peek()
    {
        return ts.top;
    }
    string get(string key)
    {
        Transaction1* active = peek();
        if (!active)
        {
            if (globalStore.find(key) != globalStore.end())
            {
                cout << globalStore[key] << endl;
            }
            else
            {
                cout << "not set" << endl;
            }
        }
        else
        {
            if (active->store.find(key) != active->store.end())
            {
                cout << active->store[key] << endl;
            }
        }
    }
    void set(string key, string value)
    {
        Transaction1* active = peek();
        if (!active)
        {
            globalStore[key] = value;
        }
        else
        {
            active->store[key] = value;
        }
    }
    void commit()
    {
        Transaction1* active = peek();
        for (auto k : active->store)
        {
            auto key = k.first, value = k.second;
            globalStore[key] = value;
            if (active->next)
            {
                active->next->store[key] = value;
            }
        }
    }
    void rollback()
    {
        if (ts.top)
        {
            ts.top->store.clear();
        }
    }
};

class Transaction2
{
public:

    unordered_map<string, string> transactionmap;
    Transaction2* next;
    Transaction2() : next(nullptr) {}
    ~Transaction2() {}
};

class TransactionStack2
{
public:
    Transaction2* top;
    int size;
    TransactionStack2() : top(nullptr) {}
    ~TransactionStack2() {}
};

class keyValStore
{
    unordered_map<string, string> globalmap;
    TransactionStack2 ts;
public:
    void begin()
    {
        Transaction2* node = new Transaction2();
        node->next = ts.top;
        ts.top = node;
        ts.size++;
    }
    void end()
    {
        Transaction2* node = ts.top;
        ts.top = node->next;
        node->next = nullptr;
        ts.size--;
        delete node;
    }
    string get(string key)
    {
        Transaction2* node = ts.top;
        if (node)
        {
            if (node->transactionmap.find(key) != node->transactionmap.end())
            {
                cout << "value for provided  key is" << node->transactionmap[key];
                return node->transactionmap[key];
            }
        }
        else
        {
            if (globalmap.find(key) != globalmap.end())
            {
                cout << "value for provided key is" << globalmap[key];
                return globalmap[key];
            }
        }
    }
    void set(string key, string value)
    {
        Transaction2* node = ts.top;
        if (node)
        {
            node->transactionmap[key] = value;
        }
        else
            globalmap[key] = value;
    }
    void commit()
    {
        Transaction2* node = ts.top;
        for (auto& element : node->transactionmap)
        {
            auto key = element.first, value = element.second;
            globalmap[key] = value;
            if(node->next)
                node->next->transactionmap[key]
        }
    }
    void rollback()
    {

    }
};


int main() {
    KeyValueStoreWithTransaction kv;
    kv.Begin();
    kv.Set("v1", "a");
    kv.Set("v2", "b");
    kv.Set("v3", "c");
    {
        kv.Begin();
        kv.Set("v1", "A");
        kv.Set("v2", "B");
        kv.Set("v3", "C");
        kv.Get("v1");
        kv.Get("v2");
        kv.Get("v3");
        kv.Commit();
        kv.End();
    }
    kv.Set("v1", "x");
    kv.Set("v2", "y");
    kv.Set("v3", "z");

    kv.Set("v4", "d");
    kv.Set("v5", "e");
    kv.Set("v6", "f");
    kv.Get("v1");
    kv.Get("v2");
    kv.Get("v3");
    kv.Commit();
    kv.End();
    kv.Get("v1");
    kv.Get("v2");
    kv.Get("v3");

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
