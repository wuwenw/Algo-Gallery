// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/
#include <numeric>

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1);
        partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
        int total_max = 0;

        auto cal = [&](int left_len, int right_len) {
            int max_left = 0;
            for (int i = left_len + right_len; i <= n; i++) {
                // check if new left array generates a new max_left
                max_left = max(max_left, prefix[i - right_len] - prefix[i - left_len - right_len]);
                // check if new right array + max_left generate a new total_max
                total_max = max(total_max, max_left + prefix[i] - prefix[i - right_len]);

            }
        };

        cal(firstLen, secondLen);
        cal(secondLen, firstLen);

        return total_max;
    }
};
