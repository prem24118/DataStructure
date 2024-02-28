// 146_lru_cache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRUCache
{
public:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    LRUCache(int capacity)
    {
        cap = capacity;
    }
    int get(int key)
    {
        if (umap.find(key) == umap.end())
        {
            return -1;
        }
        l.splice(l.begin(), l, umap[key]);
        return umap[key]->second;
    }
    void put(int key, int value)
    {
        if (umap.find(key) != umap.end())
        {
            l.splice(l.begin(), l, umap[key]);
            umap[key]->second = value;
            return;
        }
        if (l.size() == cap)
        {
            auto dkey = l.back().first;
            l.pop_back();
            umap.erase(dkey);
        }
        l.push_front({ key, value });
        umap[key] = l.begin();
    }
};

class LRUCache2
{
public:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> unomap;
    LRUCache2(int capacity)
    {
        cap = capacity;
    }
    int get(int key)
    {
        if (unomap.find(key) == unomap.end())
            return -1;
        l.splice(l.begin(), l, unomap[key]);
        return unomap[key]->second;
    }
    void put(int key, int value)
    {
        if (unomap.find(key) != unomap.end())
        {
            l.splice(l.begin(), l, unomap[key]);
            unomap[key]->second = value;
            return;
        }
        if (unomap.size() == cap)
        {
            int mapK = l.back().first;
            l.pop_back();
            unomap.erase(mapK);
        }
        l.push_front({ key, value });
        unomap[key] = l.begin();
    }
};

class LRUCache3
{
public:
    int cap;
    //this list holds all the keys of the key value pair
    list<int> keys;
    //key, pair(key position on list, value)
    unordered_map<int, pair<list<int>::iterator, int>> key_val_map;
    //constructor initializing size of lru cache to 2 - infinity
    LRUCache3(int capacity) : cap(capacity) {};
    void moveFront(int key)
    {
        //erase element in list and for that need to provide iterator as arg to erase fn
        //iterator available as first elemt of value of map, as in for the map, 
        //1st val is key, and 2nd va l is value for which there is a pair
        keys.erase(key_val_map[key].first);
        //after erasing that element from list, push that key to front
        //point the iterator in the value part of the key value pair to the beginning of the list
        keys.push_front(key);
        key_val_map[key].first = keys.begin();
    }
    int get(int key)
    {
        if (key_val_map.find(key) != key_val_map.end())
        {
            moveFront(key);
            return key_val_map[key].second;
        }
        return -1;
    }
    int put(int key, int value)
    {
        if (key_val_map.find(key) != key_val_map.end())
        {
            moveFront(key);
            key_val_map[key] = { keys.begin(), value };
        }
        else
        {
            if (keys.size() == cap)
            {
                key_val_map.erase(keys.back());
                keys.erase(keys.end());
                
            }
            keys.push_front(key);
            key_val_map[key] = { keys.begin(), value };
        }
    }

    class LRUCache4
    {
        int cap;
        list<int> keys;
        unordered_map<int, pair<list<int>::iterator, int>> key_val_map;
        LRUCache4(int capacity) : cap(capacity) {};
        void moveFront(int key)
        {
            keys.erase(key_val_map[key].first);
            keys.push_front(key);
            key_val_map[key].first = keys.begin();
        }
        int get(int key)
        {
            if (key_val_map.find(key) != key_val_map.end())
            {
                void moveFront(int key);
                return key_val_map[key].second;
            }
            return -1;
        }
        void put(int key, int value)
        {
            if (key_val_map.find(key) != key_val_map.end())
            {
                moveFront(key);
                key_val_map[key] = make_pair(keys.begin(), value);
                //key_val_map[key].second = value;
            }
            else
            {
                if (keys.size() == cap)
                {
                    key_val_map.erase(keys.back());
                    keys.pop_back();
                }
                keys.push_front(key);
                key_val_map[key] = make_pair(keys.begin(), value);
            }
        }
    };
    
    class LRUCache5
    {
    private:
        int capacity;
        list<int> keys;
        unordered_map<int, pair<list<int>::iterator, int>>  key_val_map;
    public:
        LRUCache5(int cap) : capacity(cap) {}
        void moveFront(int key)
        {
            keys.erase(key_val_map[key].first);
            keys.push_front(key);
            key_val_map[key].first = keys.begin();
        }
        int get(int key)
        {
            if (key_val_map.find(key) != key_val_map.end())
            {
                moveFront(key);
                return key_val_map[key].second;
            }
            else
                return -1;
        }
        void put(int key, int value)
        {
            if (key_val_map.find(key) != key_val_map.end())
            {
                moveFront(key);
                key_val_map[key] = make_pair(keys.begin(), value);
            }
            else
            {
                if (key_val_map.size() >= capacity)
                {
                    key_val_map.erase(keys.back());
                    keys.pop_back();
                }
                keys.push_front(key);
                key_val_map[key] = make_pair(keys.begin(), value);
            }
        }
    };
};

int main()
{
    std::cout << "Hello World!\n";
    LRUCache out(2);// = new LRUCache(2);
    out.put(5, 50);
    out.put(2, 20);
    out.get(3);
    out.put(3, 30);
    out.get(3);
    out.put(10, 100);
    out.put(10, 50);
    out.put(70, 700);
    out.get(10);
    out.put(80, 800);
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
