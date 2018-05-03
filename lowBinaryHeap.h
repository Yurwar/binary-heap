#ifndef BINARY_HEAP_LOWBINARYHEAP_H
#define BINARY_HEAP_LOWBINARYHEAP_H


class HeapLow {
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
    HeapLow(int);
    void addEl(int);
    void printHeap();
    void removeMax();
    int getMax();
    bool isEmpty();
    int getHeapSize();
    void siftUp(int);
    void siftDown(int);
};


#endif //BINARY_HEAP_LOWBINARYHEAP_H
