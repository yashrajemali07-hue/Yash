#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    // Insert
    void insert(int val) {
        heap.push_back(val);
        upHeapify(heap.size() - 1);
    }

    // Up-Heapify
    void upHeapify(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    // Delete (remove min)
    int deleteMin() {
        if (heap.size() == 0) return -1;

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        downHeapify(0);
        return root;
    }

    // Down-Heapify
    void downHeapify(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            downHeapify(smallest);
        }
    }

    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};