#include <bits/stdc++.h>
using namespace std;

class SpecialQueue {
public:
    deque<int> q;
    deque<int> mindq;
    deque<int> maxdq;

    void enqueue(int x) {
        // Insert into main queue
        q.push_back(x);

        // Maintain min deque (monotonic increasing)
        while (!mindq.empty() && mindq.back() > x) {
            mindq.pop_back();
        }
        mindq.push_back(x);

        // Maintain max deque (monotonic decreasing)
        while (!maxdq.empty() && maxdq.back() < x) {
            maxdq.pop_back();
        }
        maxdq.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return; // safety check
        int val = q.front();
        q.pop_front();

        if (!mindq.empty() && val == mindq.front()) {
            mindq.pop_front();
        }
        if (!maxdq.empty() && val == maxdq.front()) {
            maxdq.pop_front();
        }
    }

    int getFront() {
        if (q.empty()) throw runtime_error("Queue is empty");
        return q.front();
    }

    int getMin() {
        if (mindq.empty()) throw runtime_error("Queue is empty");
        return mindq.front();
    }

    int getMax() {
        if (maxdq.empty()) throw runtime_error("Queue is empty");
        return maxdq.front();
    }
};


