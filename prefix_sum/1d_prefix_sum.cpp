// https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // sum of nums[0]...nums[i] -> sum
        // stored sum in hashmap: sum of nums[0]...nums[j] -> sum - k
        // => nums[j]...nums[i] -> k
        unordered_map<int, int> sums;
        sums[0] = 1;
        int count = 0;
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sums.find(sum - k) != sums.end())
                count += sums[sum - k];
            sums[sum]++;
        }
        return count;
    }
};
