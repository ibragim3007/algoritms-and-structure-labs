//
// Created by ибра on 4/9/22.
//

#ifndef LABA8_SPLASHLIST_H
#define LABA8_SPLASHLIST_H


#include <iostream>

template<class T>
class SplashList {
private:
    int maxSize{};

    T *data;
    int last{};
    int first{};

public:
    explicit SplashList(int size) {
        this->maxSize = size;
        this->data = new T[size];
        last = 0;
        first = 0;
    }

    void pushBack(T value) {
        if (this->last - this->first == this->maxSize) {
            std::cout << "Queue overflow" << std::endl;
            return;
        }
        else this->data[(this->last++) % this->maxSize] = value;
    }

    T popFront() { return this->data[(this->first++) % this->maxSize]; }

    T popBack() { return this->data[--this->last]; }

    int getSize () { return (this->last - this->first) % (this->maxSize + 1); }

    void clear() { while(this->last - this->first) popFront(); this->last = 0; this->first = 0; }

    void print() {
        for (int i = this->first; i < this->last; ++i)
            std::cout << this->data[i] << ' ';
    }

    bool isEmpty() { return this->last - this->first == 0; }

    void pushHead (T value) { insertAt(value, 0); }

    void insertAt(T value, int index) {
        if (this->last == this->maxSize) {
            std::cout << "Overflow";
            return;
        }
        else if (index != 0) {
            this->last++;
            for (int i = index; i < this->last; ++i) {
                this->data[i + 1] = this->data[i];
            }
            this->data[index] = value;
        }
    }

    T deleteAt(int index) {
        if (index > maxSize) {
            std::cout << "\noverflow\n";
            return 1;
        }
        else if (index > this->last) {
            std::cout << "\nThis element empty\n";
            return 1;
        }
        else if (index == 0) return popFront();
        else if (index == this->last) return popBack();
        else if (index >= 0 && index <= this->last) {
            T tempValue = this->data[index];
            for (int i = index; i < this->last; ++i) {
                this->data[i] = this->data[i+1];
            }
            this->last--;
            return tempValue;
        }
    }
};



#endif //LABA8_SPLASHLIST_H
