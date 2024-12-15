#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// CircularQueue class definition
template <typename T>
class CircularQueue {
private:
    vector<T> data;
    T* queueArray;

public:
    int front, rear, size, capacity;
    // Default constructor
    CircularQueue();

    // Constructor with custom capacity
    CircularQueue(int cap);
    
    const T& get(int index) const;

    //Enque a stock entry
    void enqueue(const T& entry);

    
    T dequeue();

    // Get the size of the queue
    int getSize() const;

    T peek() const;    // Peek at the front value of the queue

    vector<T> getAllData() const; 

    void printQueue ();
};
/*    // Non-member operator<< for CircularQueue (outside the class)
    template <typename T>
    ostream& operator<<(ostream& os, const CircularQueue<T>& queue) {
    os << "[";
    for (int i = 0; i < queue.getSize(); ++i) {
        os << queue.get(i);  // Using the get() method to access elements
        if (i != queue.getSize() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
} */

#endif // CIRCULAR_QUEUE_H
