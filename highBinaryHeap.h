#ifndef BINARY_HEAP_HIGHBINARYHEAP_H
#define BINARY_HEAP_HIGHBINARYHEAP_H

class HeapHigh {
private:
    int *h;
    int heapSize;
    int arrSize;
    int getLeftChild(int i) {
        return 2 * i + 1;
    }
    int getRightChild(int i) {
        return (2 * i) + 2;
    }
    int getParent(int i) {
        return (i - 1) / 2;
    }
public:
    HeapHigh(int);
    void addEl(int);
    void printHeap();
    void siftUp(int);
    void siftDown(int);
    void removeMin();
    int getMin();
    bool isEmpty();
    int getHeapSize();
};


#endif //BINARY_HEAP_HIGHBINARYHEAP_H
