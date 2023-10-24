#include <vector>
using namespace std;

void countSort(vector<int> &array, int size, int exp);
vector<int> radixSort(vector<int> array) {
  if (array.size() == 0) return array;
  // Write your code here
  int maxNum = *max_element(array.begin(), array.end());
  for (int exp = 1; maxNum/exp > 0; exp *=10) {
    countSort(array, array.size(), exp);
  }
  return array;
}

void countSort(vector<int> &array, int size, int exp) {
  vector<int> output(size);
  int i;
  vector<int> count(10, 0);

  for (i = 0; i < size; i++) {
    count[(array[i]/exp)%10]++;
  }

  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (i = size - 1; i >= 0; i--) {
    output[count[(array[i]/exp)%10] - 1] = array[i];
    count[(array[i]/exp)%10]--;
  }
  for (i = 0; i < size; i++) {
    array[i] = output[i];
  }
}
