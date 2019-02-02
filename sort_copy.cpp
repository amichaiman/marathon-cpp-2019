#include <iostream>

using namespace std;

template<class InIter, class OutIter, class Comparator>
void SortCopy(InIter first, InIter last, OutIter result, Comparator cmp) {
    OutIter result_first = result;
    long num_elements = distance(first, last);

    /* copy vector to result*/
    while (first != last) {
        *result++ = *first++;
    }

    for (long i=0; i<num_elements; i++, result_first++) {
        for (OutIter iter=result_first; iter != result; iter++) {
            if (cmp(*iter, *result_first)) {
                iter_swap(iter, result_first);
            }
        }
    }
};
