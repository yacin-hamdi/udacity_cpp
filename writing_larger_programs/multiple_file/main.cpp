#include<iostream>
#include "increment_and_sum.h"

using std::cout;



int main()
{
    vector<int> v{ 1, 2, 3, 4 };
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}