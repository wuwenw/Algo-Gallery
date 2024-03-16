// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freqs;
        int res = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            freqs[s[right]]++;

            while (freqs[s[right]] > 1) {
                --freqs[s[left]];
                left++;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};