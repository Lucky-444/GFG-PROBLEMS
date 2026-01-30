#include <bits/stdc++.h>
using namespace std;

class kQueues {
    int n, k;
    vector<int> arr, front, rear, next;
    int free;
public:
    kQueues(int n_, int k_) {
        n = n_;
        k = k_;
        arr.resize(n);
        front.assign(k, -1);
        rear.assign(k, -1);
        next.resize(n);
        for (int i = 0; i < n-1; i++) next[i] = i+1;
        next[n-1] = -1;
        free = 0;
    }

    void enqueue(int x, int i) {
        if (isFull()) return; // ignore if full
        int idx = free;
        free = next[idx];

        if (front[i] == -1) front[i] = idx;
        else next[rear[i]] = idx;

        next[idx] = -1;
        rear[i] = idx;
        arr[idx] = x;
    }

    int dequeue(int i) {
        if (isEmpty(i)) return -1;
        int idx = front[i];
        front[i] = next[idx];
        if (front[i] == -1) rear[i] = -1;
        next[idx] = free;
        free = idx;
        return arr[idx];
    }

    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
        return free == -1;
    }
};
