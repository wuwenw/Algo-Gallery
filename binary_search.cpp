#include <vector>
using namespace std;

int binarySearchHelper(vector<int> &array, int target, int left, int right);
int binarySearch(vector<int> array, int target)
{
  // Write your code here.
  return binarySearchHelper(array, target, 0, array.size() - 1);
}

int binarySearchHelper(vector<int> &array, int target, int left, int right)
{
  if (left > right)
    return -1;
  int mid = left + (right - left) / 2;
  if (array[mid] == target)
    return mid;
  else if (array[mid] > target)
    return binarySearchHelper(array, target, left, mid - 1);
  else
    return binarySearchHelper(array, target, mid + 1, right);
}
