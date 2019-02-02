#include <iostream>
#include <cstdlib>
#include <vector>
#include "BitSet.h"

using namespace std;

bool randBit() {
    return ((static_cast<double>(rand()))/RAND_MAX) < 0.5;
}
const int SIZE=1e6;

int main() {
    clock_t t1,t2;
    t1=clock();
    BitSet<SIZE> *bitSet = new BitSet<SIZE>();
    for (int i=0; i<SIZE; i++) {
        bitSet->set(i, randBit());
    }
    for (int i=0; i<SIZE; i++) {
        bool val = bitSet->operator[](i);
    }
    delete bitSet;

    t2=clock();
    cout << "BS speed = " << (t2-t1) / (float) CLOCKS_PER_SEC << endl;
    t1=clock();

    vector<bool> *v = new vector<bool>(SIZE);

    for (int i=0; i<SIZE; i++) {
        v->operator[](i) = randBit();
    }
    for (int i=0; i<SIZE; i++) {
        bool val = v->operator[](i);
    }
    delete v;

    t2=clock();
    cout << "std::vector<bool> speed = " << (t2-t1) / (float) CLOCKS_PER_SEC << endl;
    return 0;
}

