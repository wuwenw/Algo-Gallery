// https://leetcode.com/problems/car-pooling/

// Def
// d[i] = a[0] if i == 0
//      = a[i] - a[i - 1] if i > 0
//
// property 1: adding d[i] from left to right can get array a[]
// property 2: adding x to interval a[i]...a[j]
//          == d[i] + x and d[j + 1] - x
//          (if j + 1 == n) then only need to change d[i]
//          n is the length of a[]

// reference https://leetcode.cn/circle/discuss/FfMCgb/
// 你有一个长为 n 的数组 a，一开始所有元素均为 0。
// 给定一些区间操作，其中 queries[i] = [left, right, x]，
// 你需要把子数组 a[left], a[left+1], ... a[right] 都加上 x。
// 返回所有操作执行完后的数组 a。
vector<int> solve(int n, vector<vector<int>> queries) {
    vector<int> diff(n); // 差分数组
    for (auto &q: queries) {
        int left = q[0], right = q[1], x = q[2];
        diff[left] += x;
        if (right + 1 < n) {
            diff[right + 1] -= x;
        }
    }
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1]; // 直接在差分数组上复原数组 a
    }
    return diff;
}


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        map<int, int> m;
        for (auto& trip: trips) {
            int num = trip[0], from = trip[1], to = trip[2];
            m[from] += num;
            m[to] -= num;
        }

        int v = 0;
        for (auto &[_, count]: m) {
            v += count;
            if (v > capacity) return false;
        }
        return true;
    }
};