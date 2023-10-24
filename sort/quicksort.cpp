#include <vector>
using namespace std;
void quickSortHelper(vector<int> &array, int low, int high);
int partition(vector<int> &array, int low, int high);
void swap(vector<int> &array, int i, int j);
vector<int> quickSort(vector<int> array) {
  // Write your code here.
  quickSortHelper(array, 0, array.size() - 1);
  
  return array;
}

void quickSortHelper(vector<int> &array, int low, int high) {
  if (low < high) {
    int pivot = partition(array, low, high);
    quickSortHelper(array, low, pivot - 1);
    quickSortHelper(array, pivot + 1, high);
  }
}

int partition(vector<int> &array, int low, int high) {
  int pivot = array[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      i++;
      swap(array, j, i);
    }
  }
  swap(array, i + 1, high);
  return i + 1;
}

void swap(vector<int> &array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
