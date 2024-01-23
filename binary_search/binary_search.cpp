#include <vector>
using namespace std;

// find first element in the range
// FFF TTT
int binarySearchFindFirst(vector<int>& nums, int target) {
    auto find_first = [&](function<bool(int)> check) {
        int l = 0, r = nums.size();
        while (l < r) {
            // 循环不变量：
            // nums[left-1] < target
            // nums[right] >= target
            // at the time left == right, nums[res - 1] < target && nums[res] >= target
            int mid = l + (r - l) / 2;
            if (check(mid))
                r = mid; // [left, mid)
            else
                l = mid + 1; // [mid + 1, right)
        }
        return l;
    };
    int i = find_first([&](int i) { return nums[i] >= target; });
}

// find last element in the range
// TTT FFF
int binarySearchFindLast(vector<int>& nums, int target) {
    auto find_last = [&](function<bool(int)> check) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            // nums[left] <= target
            // nums[right + 1] > target
            // at the time left == right, nums[res] <= target && nums[res + 1] > target
            int mid =  l + (r - l + 1) / 2; // adjust the mid calculation
            if (check(mid))
                l = mid;    // [mid, right)
            else
                r = mid - 1; // [left, mid - 1)
        }
        return l;
    };
    int i = find_last([&](int i) { return nums[i] <= target; });
}
