#include "CircularQueue.h"
#include "StockAnalyzer.h"  //included to use stock entry structure

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <map>

// Explicit instantiation of CircularQueue for StockEntry
template class CircularQueue<StockEntry>;

using namespace std;

    template <typename T>
    CircularQueue<T>::CircularQueue() : capacity(365), front(0), rear(0), size(0) {
        data.resize(capacity);
    }

    template <typename T>
    CircularQueue<T>::CircularQueue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        data.resize(capacity);
    }
    
    template <typename T>
    const T& CircularQueue<T>::get(int index) const {
    // Handle circular indexing
    int actualIndex = (front + index) % capacity;
    return data[actualIndex];  // Return the element at the computed index
}

     // Enqueue a stock entry (price and volume) into the circular queue
    template <typename T>
    void CircularQueue<T>::enqueue(const T& entry) {         
        if (size < capacity) {          //if queue is not full, add entry to end of queue
            data[rear] = entry;             
            rear = (rear + 1) % capacity;       //update the rear of queue
            size++;                             //update the queue size
        } 
        else {                          //if queue is full, update front and rear where front is deleted, rear
            data[rear] = entry;
            rear = (rear + 1) % capacity;
            front = (front + 1) % capacity;  // Move front to make space
        }
    }


    // Dequeue a stock entry from the circular queue
    template <typename T>
    T CircularQueue<T>::dequeue() {
        if (size == 0) {            //throw error if size is zero
            cout << "Error in dequeue, size is zero";
        }
        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }


    // Get the size of the queue
    template <typename T>
    int CircularQueue<T>::getSize() const {
        return size;
    }


    // Peek at the front value of the queue
    template <typename T>
    T CircularQueue<T>::peek() const {
        if (size == 0) {
            cout << "Erroor in peak, Size is zero";
        }
        return data[front];
    }

    // Get all data in the queue, return a vector template
    template <typename T>
    vector<T> CircularQueue<T>::getAllData() const { 
        vector<T> result;
        int current = front;
        for (int i = 0; i < size; ++i) {
            result.push_back(data[current]);
            current = (current + 1) % capacity;
        }
        return result;
    }


    //print the contents of the circularQueue
    template <typename T>
    void CircularQueue<T>::printQueue() {
        if (size == 0) {
            cout << "Queue is empty";
            return;
        }

        cout << "Circular Queue Contents" << endl;;
        int i = front;
        int count = 0;
        while (count < size) {
            cout << data[i] << endl;
            i = (i + 1) % capacity;
            count++;
        }
    }


