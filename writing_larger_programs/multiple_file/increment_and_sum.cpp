#include "vect_add_to.h"

int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    AddOneToEach(v);

    for (auto i : v) {
        total += i;
    }
    return total;
}