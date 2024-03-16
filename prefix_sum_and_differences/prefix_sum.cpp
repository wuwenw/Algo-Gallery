// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // record prefix sums;
        // if cur_sum - k exists as a prefix sum, bingo
        unordered_map<int, int> sums;
        sums[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sums.contains(sum - k)) {
                res += sums[sum - k];
            }
            sums[sum]++;
        }
        return res;
    }
};