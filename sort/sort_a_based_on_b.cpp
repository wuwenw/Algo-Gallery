// https://leetcode.com/problems/advantage-shuffle/
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int left = 0, right = n - 1;
        vector<int> res(n);
        sort(nums1.begin(), nums1.end());
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums2[i] < nums2[j];
        });

        for (int x : nums1) {
            if (x > nums2[idx[left]])
                res[idx[left++]] = x;
            else
                res[idx[right--]] = x;
        }
        return res;
    }
};