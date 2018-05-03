#include "lowBinaryHeap.h"
#include <iostream>

using namespace std;

HeapLow::HeapLow(int size) {
    arrSize = size;
    h = new int [size];
    heapSize = 0;
}

void HeapLow::printHeap() {
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

void HeapLow::removeMax() {
    if(isEmpty())
        cout << "Heap is empty";
    h[0] = h[heapSize - 1];
    heapSize --;
    if(heapSize > 0)
        siftDown(0);
}

int HeapLow::getMax() {
    if(isEmpty()) {
        cout << "Heap is empty" << endl;
    } else {
        return h[0];
    }
}

bool HeapLow::isEmpty() {
    return heapSize == 0;
}

int HeapLow::getHeapSize() {
    return heapSize;
}

void HeapLow::addEl(int elem) {
    if(heapSize == arrSize) {
        cout << "Heap's underlying storage is overflow" << endl;
    } else {
        heapSize++;
        h[heapSize - 1]= elem;
        siftUp(heapSize - 1);
    }
}

void HeapLow::siftUp(int i) {
    int parent;
    if(i != 0) {
        parent = getParent(i);
        if(h[parent] < h[i]) {
            int tmp = h[parent];
            h[parent] = h[i];
            h[i] = tmp;
            siftUp(parent);
        }
    }
}

void HeapLow::siftDown(int i) {
    int left, right, max;
    left = getLeftChild(i);
    right = getRightChild(i);
    if(right >= heapSize) {
        if(left >= heapSize) {
            return;
        } else {
            max = left;
        }
    } else {
        if(h[left] <= h[right]) {
            max = right;
        } else {
            max = left;
        }
    }
    if(h[i] < h[max]) {
        int tmp = h[i];
        h[i] = h[max];
        h[max] = tmp;
        siftDown(max);
    }
}