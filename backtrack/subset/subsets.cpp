// https://leetcode.com/problems/subsets/
// 1. from the pointer of view of the input
// -> for each one, we decide if choose or not
//
// Three questions for backtracking
// a. current op? for each number with index i, decide chhose or not
// b. subproblem? construct a subset containing numbers with index >= i
// c. next subproblem? construct a subset containing numbers with index >= i + 1
// 选或者不选
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                res.push_back(cur);
                return;
            }

            // not choose current one
            dfs(i + 1);
            cur.push_back(nums[i]);
            // choose current
            dfs(i + 1);
            cur.pop_back();
        };
        dfs(0);
        return res;
    }
};


// 2. from the pointer of view of the answer
// -> we enumerate which one to choose
//
// Three questions for backtracking
// a. current op? enumerate j >= i and add it to cur
// b. sub problem? construct subset from numbers with index >= i
// c. next subproblem? construct subset from numbers with index >= j + 1
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> res;
//         vector<int> cur;

//         function<void(int)> dfs = [&](int i) {
//             res.push_back(cur);
//             if (i == n)
//                 return;
                // enumerate
//             for (int j = i; j < n; j++) {
//                 cur.push_back(nums[j]);
//                 dfs(j + 1);
//                 cur.pop_back();
//             }
//         };

//         dfs(0);
//         return res;
//     }
// };