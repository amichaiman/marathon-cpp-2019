#include <iostream>
using namespace std;

template<class InIter, class OutIter, class Comparator>
void SortCopy(InIter first, InIter last, OutIter result, Comparator cmp) {
    int size = static_cast<int>(distance(first, last));
    OutIter first_result = result;

    while (first != last) {
        *result = *first;
        first++;
        result++;
    }
    result++;

    for (int i=0; i<size-1; i++) {
        for (OutIter it=first_result; it != result; it++) {
            OutIter it_next = it;
            it_next++;
            if (cmp(it, it_next)) {
                iter_swap(it, it_next);
            }
        }
    }

};
