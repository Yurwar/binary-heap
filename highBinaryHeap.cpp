#include "highBinaryHeap.h"
#include <iostream>

using namespace std;

HeapHigh::HeapHigh(int size) {
    h = new int[size];
    heapSize = 0;
    arrSize = size;
}

void HeapHigh::siftDown(int i) {
    int left, right, min;
    left = getLeftChild(i);
    right = getRightChild(i);
    if(right >= heapSize) {
        if(left >= heapSize) {
            return;
        } else {
            min = left;
        }
    } else {
        if(h[left] <= h[right]) {
            min = left;
        } else {
            min = right;
        }
    }
    if(h[i] > h[min]) {
        int tmp = h[i];
        h[i] = h[min];
        h[min] = tmp;
        siftDown(min);
    }
}

void HeapHigh::siftUp(int i) {
    int parent;
    if(i != 0) {
        parent = getParent(i);
        if(h[parent] > h[i]) {
            int tmp = h[parent];
            h[parent] = h[i];
            h[i] = tmp;
            siftUp(parent);
        }
    }
}

void HeapHigh::addEl(int elem) {
    if(heapSize == arrSize) {
        cout << "Heap's underlying storage is overflow" << endl;
    } else {
        heapSize++;
        h[heapSize - 1] = elem;
        siftUp(heapSize - 1);
    }
}

void HeapHigh::printHeap() {
    int i = 0;
    int k = 1;
    while(i < heapSize) {
        while((i < k) && (i < heapSize)) {
            cout << h[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
}

void HeapHigh::removeMin() {
    if(isEmpty()) {
        cout << "Heap is empty" << endl;
    } else {
        h[0] = h[heapSize - 1];
        heapSize--;
        if(heapSize > 0)
            siftDown(0);
    }
}

int HeapHigh::getMin() {
    if(isEmpty()) {
        cout << "Heap is empty" << endl;
    } else {
        return h[0];
    }

}

bool HeapHigh::isEmpty() {
    return heapSize == 0;
}

int HeapHigh::getHeapSize() {
    return heapSize;
}