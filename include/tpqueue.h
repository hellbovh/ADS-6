// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int first, last, count;
 public:
    TPQueue() : first(0), last(0), count(0) {
        arr = new T[size];
    }
    bool isEmpty() const;
    bool isFull() const;
    void push(const T& value);
    const T& pop();
};

template <typename T, int size>
bool TPQueue<T, size>::isEmpty() const {
    return count == 0;
}

template <typename T, int size>
bool TPQueue<T, size>::isFull() const {
    return count == size;
}

template <typename T, int size>
void TPQueue<T, size>::push(const T& value) {
    if (isFull()) {
        throw std::string("Queue is full!");
    } else {
        int tmp = last - 1;
        while (tmp >= first && value.prior > arr[tmp].prior) {
            arr[tmp + 1] = arr[tmp];
            tmp--;
        }
        arr[tmp + 1] = value;
        last++;
        count++;
        if (last > size) {
            last -= size;
        }
    }
}

template <typename T, int size>
const T& TPQueue<T, size>::pop() {
    if (isEmpty()) {
        throw std::string("Queue is empty!");
    } else {
        T& data = arr[first];
        first++;
        count--;
        if (first > size) {
            first -= size;
        }
        return data;
    }
}

struct SYM {
    char ch;
    int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
