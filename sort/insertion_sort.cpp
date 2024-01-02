#include <vector>
using namespace std;

void insertionSort(vector<int>& array) {
  // Write your code here.
  for (int i = 1; i < array.size(); i++) {
    int j = i;
    while (j > 0 && array[j - 1] > array[j])
    {
      swap(array[j - 1], array[j]);
      j--;
    }
  }
}
