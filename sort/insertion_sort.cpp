#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
  for (int i = 1; i < array.size(); i++) {
    int key = array[i];
    int j = i - 1;
    for (; j >= 0; j--) {
      if (array[j] < key) {
        break;
      }
      array[j + 1] = array[j];
    }
    array[j + 1] = key;
  }
  return array;
}
