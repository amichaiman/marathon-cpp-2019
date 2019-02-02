//
// Created by amichai on 02/02/19.
//

#ifndef MARATHON_CPP_2019_BITSET_H
#define MARATHON_CPP_2019_BITSET_H
#include <string>
using namespace std;

template <unsigned int N>
class BitSet {
public:
    explicit BitSet();
    BitSet(const bool &bool_bit_set);
    bool oeprator[](const int index) const;
    void set(const int index, bool value);
    void flip();
    void flip(const int index);
    int count() const;
    int size() const;
    operator string() const;
    class BitSetIterator {
    public:
        BitSetIterator& operator[](const int index);
        BitSetIterator& operator++();
        BitSetIterator& operator--();
        bool operator*() const;
        bool operator==(const BitSetIterator& rhs) const;
        bool operator!=(const BitSetIterator& rhs) const;
    private:
        int index;
    };
    BitSetIterator begin();
    BitSetIterator end();
private:
    static const int BITS_IN_BYTE = 8;
    int array[N/(BITS_IN_BYTE*sizeof(int))];
};
#endif //MARATHON_CPP_2019_BITSET_H
