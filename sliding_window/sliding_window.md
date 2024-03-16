**滑动窗口**
滑动窗口是一种特殊的同向双指针，通过维护窗口内的单调性来寻找符合条件的子数组, 时间复杂度为O(n)

定长滑动窗口
窗口的大小固定为k, 移动右端点i, 若当前窗口 `[left, i]` size大于k则移动左端点left。尝试用当前窗口更新答案。
```
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 
Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int left = 0, cnt = 0, res = 0;
        unordered_set<char> dict{'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++) {
            cnt += dict.contains(s[i]);
            while (i - left + 1 > k) {
                cnt -= dict.contains(s[left]);
                left++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
```

不定长滑动窗口
窗口可以有任意大小，维护一个满足条件的最大/最小的窗口
```
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
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
```
不定长滑窗 - 统计子数组个数
维护窗口，根据题意计算子数组个数。如下题中所有右边包含当前窗口的子数组都是valid，所以我们使用`n - i`来计算。
```
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        int left = 0;
        ll res = 0, cnt = 0;
        unordered_map<int, int> freqs;
        for (int i = 0; i < n; i++) {
            cnt += freqs[nums[i]]++;
            while (cnt >= k) {
                res += n - i;
                cnt -= --freqs[nums[left]];
                left++;
            }
        }
        return res;
    }
};

```
多指针滑动窗口
```
https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        using ll = long long;
        ranges::sort(nums);
        int n = nums.size();
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
            auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
            ans += r - l;
        }
        return ans;
    }
};
```

题单 by 灵茶山艾府
https://leetcode.cn/circle/discuss/0viNMK/
