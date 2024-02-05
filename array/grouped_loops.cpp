// template
int grouped_loops(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && ...) {
            i++;
        }

        // divide start to i - 1 as one group
        // the next group will start from i
    }
}

// https://leetcode.com/problems/consecutive-characters/description/
class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int i = 0, res = 0;
        while (i < n) {
            int start = i;
            char c = s[i];
            i++;
            while (i < n && s[i] == c) {
                i++;
            }
            res = max(res, i - start);
        }
        return res;
    }
};

// https://leetcode.com/problems/find-if-array-can-be-sorted/
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> back_up(nums);
        sort(back_up.begin(), back_up.end());
        while (i < n) {
            int start = i;
            int cnt = __builtin_popcount(nums[i]);
            i++;
            while (i < n && cnt == __builtin_popcount(nums[i])) {
                i++;
            }
            sort(nums.begin() + start, nums.begin() + i);
        }
        return nums == back_up;
    }
};

// https://leetcode.com/problems/longest-alternating-subarray/description/
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, res = -1;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] != 1) {
                i++;
                continue;
            }
            
            // start position
            int i0 = i;
            i += 2;

            while (i < n && nums[i] == nums[i0] + (i - i0) % 2) {
                i++;
            }
            res = max(res, i - i0);
            // i0 to i - 1 is valid
            i--;
        }
        return res;
    }
};
