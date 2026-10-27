#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include <cassert>
#include <algorithm>
#include <utility>

template <typename T>
class ArrayList {
    T* tab;
    std::size_t msize;
    std::size_t last;
public:
    ArrayList(std::size_t s=10) : msize(s), last(0) {
        assert(s > 0);
        tab = new T[s];
        assert(tab != nullptr);
    }
    
    ~ArrayList() { 
        delete[] tab; 
    }

    ArrayList(const ArrayList& other);
    ArrayList(ArrayList&& other);
    ArrayList& operator=(const ArrayList& other);
    ArrayList& operator=(ArrayList&& other);

    bool empty() const { return last == 0; }
    bool full() const { return last == msize; }
    std::size_t size() const { return last; }
    std::size_t max_size() const { return msize; }
    
    void push_front(const T& item);
    void push_front(T&& item);
    void push_back(const T& item);
    void push_back(T&& item);
    
    T& front();
    T& back();
    void pop_front();
    void pop_back();
    void clear();
    
    void display() const;
    void display_reversed() const;
    void reverse();
    void sort();
    void merge(ArrayList& other);

    T& operator[](std::size_t pos);
    const T& operator[](std::size_t pos) const;
    void erase(std::size_t pos);
    int index(const T& item);
    void insert(std::size_t pos, const T& item);
    void insert(std::size_t pos, T&& item);

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (std::size_t i = 0; i < L.last; ++i) {
            os << L.tab[i] << " ";
        }
        return os;
    }
};

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other) : msize(other.msize), last(other.last) {
    tab = new T[msize];
    std::copy(other.tab, other.tab + other.last, tab);
}

template <typename T>
ArrayList<T>::ArrayList(ArrayList&& other) : tab(other.tab), msize(other.msize), last(other.last) {
    other.tab = nullptr;
    other.msize = 0;
    other.last = 0;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
    if (this != &other) {
        T* new_tab = new T[other.msize];
        std::copy(other.tab, other.tab + other.last, new_tab);
        delete[] tab;
        tab = new_tab;
        msize = other.msize;
        last = other.last;
    }
    return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList&& other) {
    if (this != &other) {
        delete[] tab;
        tab = other.tab;
        msize = other.msize;
        last = other.last;
        other.tab = nullptr;
        other.msize = 0;
        other.last = 0;
    }
    return *this;
}

template <typename T>
void ArrayList<T>::push_front(const T& item) {
    assert(!full());
    std::copy_backward(tab, tab + last, tab + last + 1);
    tab[0] = item;
    ++last;
}

template <typename T>
void ArrayList<T>::push_front(T&& item) {
    assert(!full());
    std::copy_backward(tab, tab + last, tab + last + 1);
    tab[0] = std::move(item);
    ++last;
}

template <typename T>
void ArrayList<T>::push_back(const T& item) {
    assert(!full());
    tab[last] = item;
    ++last;
}

template <typename T>
void ArrayList<T>::push_back(T&& item) {
    assert(!full());
    tab[last] = std::move(item);
    ++last;
}

template <typename T>
T& ArrayList<T>::front() {
    assert(!empty());
    return tab[0];
}

template <typename T>
T& ArrayList<T>::back() {
    assert(!empty());
    return tab[last - 1];
}

template <typename T>
void ArrayList<T>::pop_front() {
    assert(!empty());
    std::copy(tab + 1, tab + last, tab);
    --last;
}

template <typename T>
void ArrayList<T>::pop_back() {
    assert(!empty());
    --last;
}

template <typename T>
void ArrayList<T>::clear() {
    last = 0;
}

template <typename T>
void ArrayList<T>::display() const {
    for (std::size_t i = 0; i < last; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void ArrayList<T>::display_reversed() const {
    for (std::size_t i = last; i > 0; --i) {
        std::cout << tab[i - 1] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void ArrayList<T>::reverse() {
    std::reverse(tab, tab + last);
}

template <typename T>
void ArrayList<T>::sort() {
    std::sort(tab, tab + last);
}

template <typename T>
void ArrayList<T>::merge(ArrayList& other) {
    assert(last + other.last <= msize);
    std::copy(other.tab, other.tab + other.last, tab + last);
    std::inplace_merge(tab, tab + last, tab + last + other.last);
    last += other.last;
    other.clear();
}

template <typename T>
T& ArrayList<T>::operator[](std::size_t pos) {
    assert(pos < last);
    return tab[pos];
}

template <typename T>
const T& ArrayList<T>::operator[](std::size_t pos) const {
    assert(pos < last);
    return tab[pos];
}

template <typename T>
void ArrayList<T>::erase(std::size_t pos) {
    assert(pos < last);
    std::copy(tab + pos + 1, tab + last, tab + pos);
    --last;
}

template <typename T>
int ArrayList<T>::index(const T& item) {
    for (std::size_t i = 0; i < last; ++i) {
        if (tab[i] == item) return static_cast<int>(i);
    }
    return -1;
}

template <typename T>
void ArrayList<T>::insert(std::size_t pos, const T& item) {
    assert(!full());
    assert(pos <= last);
    std::copy_backward(tab + pos, tab + last, tab + last + 1);
    tab[pos] = item;
    ++last;
}

template <typename T>
void ArrayList<T>::insert(std::size_t pos, T&& item) {
    assert(!full());
    assert(pos <= last);
    std::copy_backward(tab + pos, tab + last, tab + last + 1);
    tab[pos] = std::move(item);
    ++last;
}

#endif