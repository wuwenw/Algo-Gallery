#include <vector>
using namespace std;
void merge(vector<int> &array, int left, int mid, int right);
void mergeSortHelper(vector<int> &array, int left, int right);
vector<int> mergeSort(vector<int> array) {
  // Write your code here.
  mergeSortHelper(array, 0, array.size() - 1);
  return array;
}

void mergeSortHelper(vector<int> &array, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSortHelper(array, left, mid);
    mergeSortHelper(array, mid + 1, right);
    merge(array, left, mid, right);
  }
}

void merge(vector<int> &array, int left, int mid, int right) {
  int leftSize = mid - left + 1;
  int rightSize = right - mid;
  vector<int> leftArray (leftSize);
  vector<int> rightArray (rightSize);

  for (int i = 0; i < leftSize; i++) {
    leftArray[i] = array[left + i];
  }

  for (int i = 0; i < rightSize; i++) {
    rightArray[i] = array[mid + i + 1];
  }

  int leftIndex = 0;
  int rightIndex = 0;
  int mergeIndex = left;

  while (leftIndex < leftSize && rightIndex < rightSize) {
    if (leftArray[leftIndex] <= rightArray[rightIndex]) {
      array[mergeIndex] = leftArray[leftIndex];
      leftIndex++;
    } else {
      array[mergeIndex] = rightArray[rightIndex];
      rightIndex++;
    }
    mergeIndex++;
  }

  while (leftIndex < leftSize) {
    array[mergeIndex] = leftArray[leftIndex];
    leftIndex++;
    mergeIndex++;
  }

    while (rightIndex < rightSize) {
      array[mergeIndex] = rightArray[rightIndex];
      rightIndex++;
      mergeIndex++;
  }

}
