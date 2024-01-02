#include <vector>
#include <algorithm>  // for max_element
using namespace std;

void countSort(vector<int> &array, int exp);

vector<int> radixSort(vector<int> &array) {
    if (array.empty()) return array;

    int maxNum = *max_element(array.begin(), array.end());

    for (int exp = 1; maxNum/exp > 0; exp *= 10) {
        countSort(array, exp);
    }

    return array;
}

void countSort(vector<int> &array, int exp) {
    vector<int> output(array.size());
    vector<int> count(10, 0);

    for (const auto &num : array) {
        count[(num/exp) % 10]++;
    }

    for (size_t i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = array.size() - 1; i >= 0; i--) {
        output[count[(array[i]/exp) % 10] - 1] = array[i];
        count[(array[i]/exp) % 10]--;
    }

    array = output;
}
