#include <iostream>
#include <fstream>

using namespace std;

void swap(int&, int&);

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
    void printArr() {
        for(int i = 0; i < arrSize; i++) {
            cout << h[i] << "|";
        }
    };
    int removeMax();
    void maxHeapify(int);
    int getMax();
    bool isEmpty();
    int getHeapSize() {
        return heapSize;
    }
};

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
    void printArr() {
        for(int i = 0; i < arrSize; i++) {
            cout << h[i] << "|";
        }
    };
    void removeMin();
    void siftUp(int);
    void siftDown(int);
    int getMin();
    bool isEmpty();
    int getHeapSize() {
        return heapSize;
    }
};

void countMedian(HeapHigh& hh, HeapLow& hl, int x, ofstream& output) {
    if(hl.isEmpty() || x < hl.getMax()) {
        hl.addEl(x);
    } else {
        hh.addEl(x);
    }

    if(hl.getHeapSize() - hh.getHeapSize() == 2) {
        hh.addEl(hl.getMax());
        hl.removeMax();
    } else if(hh.getHeapSize() - hl.getHeapSize() == 2) {
        hl.addEl(hh.getMin());
        hh.removeMin();
    }

    if(hl.getHeapSize() == hh.getHeapSize()) {
        output << hl.getMax() << ' ' << hh.getMin() << endl;
    }

    if(hl.getHeapSize() > hh.getHeapSize()) {
        output << hl.getMax() << endl;
    } else if(hh.getHeapSize() > hl.getHeapSize()) {
        output << hh.getMin() << endl;
    }
}

int main(int argc, char* argv[]) {
    ifstream input("./input_09_100.txt");
    ofstream output("./output.txt");

    int arrSize;
    input >> arrSize;
    HeapHigh hh(arrSize + 1);
    HeapLow hl(arrSize + 1);

    int x;
    for(int i = 0; i < arrSize; i++) {
        input >> x;
        countMedian(hh, hl, x, output);
    }
    /*
    for(int i = 0; i < arrSize; i++) {
        cout << hh.getMin() << ' ';

        hh.removeMin();
    }
    cout << endl;

    for(int i = 0; i < arrSize; i++) {
        cout << hl.getMax() << ' ';
        hl.removeMax();

    }
     */
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

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

void HeapLow::addEl(int elem) {
    int i, parent;
    i = heapSize;
    h[i] = elem;
    parent = (i - 1) / 2;
    while (parent >= 0 && i > 0) {
        if(h[i] > h[parent]) {
            swap(h[i], h[parent]);
        }
        i = parent;
        parent = (i - 1) / 2;
    }
    heapSize++;
}

void HeapLow::maxHeapify(int i) {
    int left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if(left < heapSize) {
        if(h[i] < h[left]) {
            swap(h[i], h[left]);
            maxHeapify(left);
        }
    }
    if(right < heapSize) {
        if(h[i] < h[right]) {
            swap(h[i], h[right]);
            maxHeapify(right);
        }
    }
}

int HeapLow::removeMax() {
    int x;
    x = h[0];
    h[0] = h[heapSize - 1];
    heapSize--;
    maxHeapify(0);
    return x;
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

//------------------------------------------------------
//----------------------------------------------------
//-----------------------------------------------------
//-----------------------------------------------------


HeapHigh::HeapHigh(int size) {
    h = new int[size];
    heapSize = 0;
    arrSize = size;
}

void HeapHigh::siftUp(int i) {
    int parent;
    if(i != 0) {
        parent = getParent(i);
        if(h[parent] > h[i]) {
            swap(h[parent], h[i]);
            siftUp(parent);
        }
    }
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
        swap(h[i], h[min]);
        siftDown(min);
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