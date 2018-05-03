#include <fstream>
#include "highBinaryHeap.h"
#include "lowBinaryHeap.h"

using namespace std;

void countMedian(HeapHigh&, HeapLow&, int x, ofstream& );

int main(int argc, char* argv[]) {
    ifstream input(argv[1]);
    ofstream output(argv[2]);

    int arrSize;
    input >> arrSize;
    HeapHigh hh(arrSize);
    HeapLow hl(arrSize);

    int x;
    for(int i = 0; i < arrSize; i++) {
        input >> x;
        countMedian(hh, hl, x, output);
    }

    input.close();
    output.close();
}

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