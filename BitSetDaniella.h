#ifndef BIT_SET_H
#define BIT_SET_H
using namespace std;

#include <string>
#include <vector>

#define MY_SIZE(_size) \
        (SIZE/(sizeof(char)*BITS_IN_BYTE) \
         + (size%(sizeof(char)*BITS_IN_BYTE)!=0))

template <int SIZE=10>
class BitSet {
public:
    BitSet();
    explicit BitSet(bool *elements);
    bool operator[](unsigned int i) const;
    void set(unsigned int i, bool val);
    void flip(unsigned int i);
    void flip();
    int count() const;
    int size() const;
    operator std::string() const;

    class iterator {
    public:
        iterator(BitSet& bitSet) :bitSet(bitSet), index(0){}
        bool operator*();
        iterator& operator++();
        iterator& operator--();
        bool operator==(const iterator& rhs);
    private:
        BitSet& bitSet;
        int index;
    };

    iterator begin() {
        return iterator(*this);
    }
    iterator end();

private:
    unsigned char elements[MY_SIZE(SIZE)]; //number of bytes needed by us = SIZE/8 + 1 if necessery
};
#endif

int main() {
    BitSet<100> b;
    Bitset<100>::iterator it = b.begin();


    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(7);


    vector<int>::iterator it = v.begin();
    (++it)++;
}
