// 300
// optimization
// greey + binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for (int i = 0; i < nums.size(); i++) {
            // find first item >= current
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            // if not exist, meaning dp is monotonic so far 
            if (it == dp.end())
                dp.push_back(nums[i]);
            else
                // replace it with nums[i] to allow smaller incoming numbers
                *it = nums[i];
        }
        return dp.size();
    }
};

// base solutoin: for nums[i], find nums[j] < nums[i] where j < i and has biggest dp[j]
// dp[i] = dp[j] and dp[i]++
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();

//         // dp(i) = dp(j) + 1
//         vector<int> dp(n);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[j] < nums[i]) {
//                     dp[i] = max(dp[i], dp[j]);
//                 }
//             }
//             dp[i]++;
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };
