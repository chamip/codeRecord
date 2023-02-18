//
// Created by Administrator on 2023/2/18.
//
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class MyHashMap {
private:
    static const int base = 769;
    vector<list<pair<int, int>>> data;
    static int hash(int key) {
        return key % base;
    }
public:
    MyHashMap():data(base) {}

    void put(int key, int value) {
        int h = hash(key);
        auto it = data[h].begin();
        cout << typeid(it).name() << endl;
        for (; it != data[h].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return ;
            }
        }
        data[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); ++it) {
            if (it->first == key) {
                data[h].erase(it);
                return ;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *m = new MyHashMap();
    m->put(1,1);
    m->put(2,2);
    m->get(1);
    delete m;
    return 0;
}
