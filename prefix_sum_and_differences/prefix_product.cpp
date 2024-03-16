// https://leetcode.com/problems/subarray-product-less-than-k/description/
// sliding window
// numbers > 0
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0;
        int prod = 1, ans = 1, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k)
                prod /= nums[left++];
            // every new element from right can form (right - left + 1) subarrays
            ans += right - left + 1;
        }
        return ans;
    }
};