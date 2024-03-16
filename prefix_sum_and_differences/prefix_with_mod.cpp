// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prefix_sum ;
        prefix_sum[0] = 1;
        int prefix_mod = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // mod twice to remove negative
            // prefix[i] = ak + r0
            // prefix[j] = bk + r1
            // prefix[j] - prefix[i] = k(b - a) + r1 - r0
            // r1 - r0 = ck to make subarray divisible by k
            prefix_mod = (prefix_mod + nums[i] % k + k) % k;
            res += prefix_sum[prefix_mod]++;
        }

        return res;
    }

};

