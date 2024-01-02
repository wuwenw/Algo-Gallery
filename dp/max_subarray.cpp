// https://leetcode.com/problems/maximum-subarray/submissions/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int cur_sum = 0;
        for (int num : nums)
        {
            // dp[i] = max(dp[i - 1] + num, num)
            cur_sum = max(cur_sum + num, num);
            max_sum = max(max_sum, cur_sum);
        }

        return max_sum;
    }
};
