// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        int left = 0;
        vector<int> res;

        for (int right = 0; right < n; ++right) {
            while (!dq.empty() && nums[right] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(right);

            if (right - left + 1 > k) {
                if (dq.front() == left)
                    dq.pop_front();
                ++left;
            }

            if (right - left + 1 == k)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};