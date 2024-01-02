// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // store index
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && dq.front() < i - k + 1)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[i] > nums[dq.back()])
            {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
