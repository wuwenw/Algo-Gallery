// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // rotated
            if (nums[mid] >= nums[0]) {
                if (nums[mid] >= target && nums[0] <= target)
                    r = mid;
                else
                    l = mid +1;
            }
            else {
                // unrotated
                if (nums[mid] < target && nums[n - 1] >= target)
                    l = mid + 1;
                else
                    r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
