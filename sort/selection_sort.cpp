#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
  for (int i = 0; i < array.size(); i++) {
    int index = i;
    for (int j = i + 1; j < array.size(); j++) {
      if (array[j] < array[index]) {
        index = j;
      }
    }
    int temp = array[i];
    array[i] = array[index];
    array[index] = temp;
  }
  return array;
}
