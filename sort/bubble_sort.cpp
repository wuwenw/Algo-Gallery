#include <vector>
using namespace std;

void bubbleSort(vector<int>& array) {
  int size = array.size();
  bool swapped = true;
  for (int i = 0; i < size - 1 && swapped; i++) {
    swapped = false;
    for (int j = 0; j < size - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        swap(array[j], array[j + 1]);
        swapped = true;
      }
    }
  }
}
