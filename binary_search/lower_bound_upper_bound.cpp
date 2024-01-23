#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// lower bound
// Returns an iterator pointing to the first element in the range [first, last) such that element < value (or comp(element, value)) is false, 
// (i.e. that is greater than or equal to value), or last if no such element is found.

// Lower bound - Increasing Order
void lower_bound_increasing() {
    vector<int> nums{0, 2, 3, 6};
    int tar = 4;

    auto comp = [&](int element, int value) {
        return element < value;
    };
    
    // lower bound find the first element that makes comp false
    // so element >= value
    auto it = lower_bound(nums.begin(), nums.end(), tar, comp);
}

// Lower bound - Decreasing Order
void lower_bound_decreasing() {
    vector<int> nums{6, 3, 2, 0};
    int tar = 4;

    // lower bound find the first element that makes comp false
    // so element <= value
    auto comp = [](int element, int value) { return element > value; };
    auto it = lower_bound(nums.begin(), nums.end(), tar, comp);
}


// upper bound
// Returns an iterator pointing to the first element in the range [first, last) such that value < element 
// (or comp(value, element)) is true (i.e. that is strictly greater than value), or last if no such element is found.

// Upper bound - Increasing Order
void upper_bound_increasing() {
    vector<int> nums{0, 2, 3, 6};
    int tar = 4;

    auto comp = [&](int value, int element) {
        return value < element;
    };
    
    // upper bound find the first element that makes comp true
    // so element > value
    auto it = upper_bound(nums.begin(), nums.end(), tar, comp);
}

// Upper bound - Decreasing Order
void upper_bound_decreasing() {
    vector<int> nums{6, 3, 2, 0};
    int tar = 4;

    // upper bound find the first element that makes comp true
    // so element < value
    auto comp = [](int value, int element) { return value > element; };
    auto it = upper_bound(nums.begin(), nums.end(), tar, comp);
}
