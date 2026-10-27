#include <iostream>
#include <cassert>
#include "arraylist.hpp"

int main() {
    ArrayList<int> list(10);
    
    assert(list.empty());
    assert(list.max_size() == 10);
    assert(list.size() == 0);

    list.push_back(10);
    list.push_back(30);
    assert(list.size() == 2);
    assert(list.back() == 30);

    list.push_front(5);
    assert(list.size() == 3);
    assert(list.front() == 5);
    assert(list[1] == 10);

    list.insert(2, 20);
    assert(list.size() == 4);
    assert(list[2] == 20);

    assert(list.index(20) == 2);
    assert(list.index(99) == -1);

    list.erase(1);
    assert(list.size() == 3);
    assert(list[1] == 20);

    list.pop_front();
    assert(list.front() == 20);
    
    list.pop_back();
    assert(list.back() == 20);
    assert(list.size() == 1);
    
    list.clear();
    assert(list.empty());

    ArrayList<int> listA(10);
    listA.push_back(1);
    listA.push_back(5);

    ArrayList<int> listB(10);
    listB.push_back(3);
    listB.push_back(7);

    listA.merge(listB);
    assert(listA.size() == 4);
    assert(listA[0] == 1);
    assert(listA[1] == 3);
    assert(listA[2] == 5);
    assert(listA[3] == 7);
    assert(listB.empty());

    listA.reverse();
    assert(listA[0] == 7);
    assert(listA[3] == 1);

    listA.sort();
    assert(listA[0] == 1);
    assert(listA[3] == 7);

    return 0;
}