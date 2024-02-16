// https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur(n);
        unordered_set<int> visited;

        function<void(int, unordered_set<int>&)> dfs = [&](int i, unordered_set<int>& visited) {
            if (i == n) {
                res.push_back(cur);
                return;
            }

            for (int j = 0; j < n; j++) {
                if (!visited.contains(j)) {
                    visited.emplace(j);
                    cur[i] = nums[j];
                    dfs(i + 1, visited);
                    visited.erase(j);
                }
            }
        };
        dfs(0, visited);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> res;
//         vector<int> cur(n);
//         vector<bool> visited(n);

//         function<void(int)> dfs = [&](int i) {
//             if (i == n) {
//                 res.push_back(cur);
//                 return;
//             }

//             for (int j = 0; j < n; j++) {
//                 if (!visited[j]) {
//                     visited[j] = true;
//                     cur[i] = nums[j];
//                     dfs(i + 1);
//                     visited[j] = false;
//                 }
//             }
//         };
//         dfs(0);
//         return res;
//     }
// };
