#include <vector>
using namespace std;
// to find maximum subarray
int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
  int maxSum = INT_MIN;
  int curSum = 0;
  for (int i = 0; i < array.size(); i++) {
    curSum = max(curSum + array[i], array[i]);
    maxSum = max(maxSum, curSum);
  }
  return maxSum;
}
