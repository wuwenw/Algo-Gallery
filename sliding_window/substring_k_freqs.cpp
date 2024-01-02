// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        int left = 0, res = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            freqs[nums[right]]++;

            while (freqs[nums[right]] > k)
            {
                freqs[nums[left++]]--;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};
