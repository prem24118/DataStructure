// key_value_store2_design.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

class KeyValueStore {
public:
    void set(const std::string& key, const std::string& value) {
        data[key] = value;
    }

    std::string get(const std::string& key) {
        if (data.find(key) != data.end()) {
            return data[key];
        }
        return "Key not found.";
    }

    void begin() {
        transactionStack.push_back(data);
    }

    void commit() {
        if (!transactionStack.empty()) {
            //data = transactionStack.back();
            transactionStack.pop_back();
            std::cout << "Transaction committed." << std::endl;
        }
        else {
            std::cout << "No active transaction to commit." << std::endl;
        }
    }

    void rollback() {
        if (!transactionStack.empty()) {
            data = transactionStack.back();
            transactionStack.pop_back();
            std::cout << "Transaction rolled back." << std::endl;
        }
        else {
            std::cout << "No active transaction to roll back." << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::string> data;
    std::vector<std::unordered_map<std::string, std::string>> transactionStack;
};

class keyValueStore2
{
public:
    std::string get(std::string key)
    {
        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }
        else
            std::cout << "nothing to be returned";
    }

    void set(std::string key, std::string value)
    {
        mp[key] = value;
    }

    void begin()
    {
        transactionStack.push_back(mp);
    }

    void commit()
    {
        if (!transactionStack.empty())
        {
            mp = transactionStack.back();
            transactionStack.pop_back();
            std::cout << "Successfully committed";
        }
        else
            std::cout << "Nothing to commit";
    }

    void rollback()
    {
        if (!transactionStack.empty())
        {
            transactionStack.pop_back();
            std::cout << "Successfully rolled back";
        }
        else
        {
            std::cout << "nothing to rollback";
        }
    }

private:
    std::unordered_map<std::string, std::string> mp;
    std::vector<std::unordered_map<std::string, std::string>> transactionStack;
};

int main() {
    /*KeyValueStore kvStore;
    std::string command;

    std::cout << "Interactive Key/Value Store" << std::endl;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "SET") {
            std::string key, value;
            std::cin >> key >> value;
            kvStore.set(key, value);
            std::cout << "Value set." << std::endl;
        }
        else if (command == "GET") {
            std::string key;
            std::cin >> key;
            std::cout << "Value: " << kvStore.get(key) << std::endl;
        }
        else if (command == "BEGIN") {
            kvStore.begin();
            std::cout << "Transaction started." << std::endl;
        }
        else if (command == "COMMIT") {
            kvStore.commit();
        }
        else if (command == "ROLLBACK") {
            kvStore.rollback();
        }
        else if (command == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;*/
    KeyValueStore kvStore;
    std::string command;

    while (1)
    {
        std::cout << ">";
        std::cin >> command;

        if (command == "SET");
        {
            std::string key, value;
            std::cin >> key >> value;
            kvStore.set(key, value);
            std::cout << "Value set" << std::endl;
        }
        if (command == "GET")
        {
            std::string key;
            std::cin >> key;
            std::cout << "Value" << kvStore.get(key) << std::endl;
        }
        if (command == "COMMIT")
        {
            kvStore.commit();
        }
        if (command == "ROLLBACK")
        {
            kvStore.rollback();
        }
        if (command == "EXIT")
        {
            break;
        }
    }

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
