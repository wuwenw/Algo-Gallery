#include <vector>
using namespace std;
void swap(vector<int> &array, int i, int j);
void heapify(vector<int> &array, int size, int index);
vector<int> heapSort(vector<int> array) {
  // Write your code here.
  int n = array.size();
  for (int i = n/2 - 1; i >= 0; i--) {
    heapify(array, n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(array, 0, i);
    heapify(array, i, 0);
  }
  return array;
}

void heapify(vector<int> &array, int size, int index) {
  int largest = index;
  int l = index*2+1;
  int r = index*2+2;
  if (l < size && array[l] > array[largest]) {
    largest = l;
  }
  if (r < size && array[r] > array[largest]) {
    largest = r;
  }
  if (largest != index) {
    swap(array, largest, index);
    heapify(array, size, largest);
  } 
}

void swap(vector<int> &array, int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
