// https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/
class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        // f[i][j] -> 前j个数分成i段
        // f[i][j] = 不选 -> f[i][j - 1]
        //           选   -> max{f[i - 1][L] + sum[L ... j-1] * -1^(i+1)*(k-i+1)} for L = i - 1 ... j - 1
        // w = -1^(i+1)*(k-i+1) = -1 * (k - i + 1) if i % 2 == 0
        //                      =  1 * (k - i + 1) if i % 2 == 1
        // sum[L ... j - 1] = prefix sum S[j] - S[L]
        // s[j] * w + max{f[i - 1][L] - S[L] * w} for L in range i - 1 ... j - 1
        // using mx = max(max, f[i - 1][j] - S[j] * w) for each j
        // -> s[j] * w + mx
        // f[i][j] = max(f[i][j - 1], s[j] * w + mx)
        // j in range [i, n - k + i + 1)
        // i in range [1, k + 1)
        // f[i][i - 1] = -inf -> can't choose i group from i - 1 numbers
        // f[0][j] = 0 -> not choose group
        // res = f[k][n]
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1));
        vector<ll> sums(n + 1);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }

        for (int i = 1; i < k + 1; i++) {
            dp[i][i - 1] = LLONG_MIN;
            ll mx = LLONG_MIN;
            int w = i % 2 == 1 ? 1 : -1;
            w *= k - i + 1;
            for (int j = i; j < n - k + i + 1; j++) {
                mx = max(mx, dp[i - 1][j - 1] - sums[j - 1] * w);
                dp[i][j] = max(dp[i][j - 1], sums[j] * w + mx);
            } 
        }
        return dp[k][n];
    }
};

// Ref: //leetcode.cn/problems/maximum-strength-of-k-disjoint-subarrays/solutions/2678061/qian-zhui-he-hua-fen-xing-dpshi-zi-bian-ap5z5/
// 题单：划分型 DP ①
// 将序列分成（恰好/至多）kkk 个连续区间，求解与这些区间有关的最优值。

// 410. 分割数组的最大值
// 813. 最大平均值和的分组 1937
// 1278. 分割回文串 III 1979
// 1335. 工作计划的最低难度 2035
// 2478. 完美分割的方案数 2344
// 2911. 得到 K 个半回文串的最少修改次数 2608
// 题单：划分型 DP ②
// 最小化/最大化分割出的区间个数等。

// 132. 分割回文串 II
// 2707. 字符串中的额外字符 1736
// 2767. 将字符串分割为最少的美丽子字符串 1865
// 1105. 填充书架 2014
// 2547. 拆分数组的最小代价 2020
// 2463. 最小移动总距离 2454
// 2977. 转换字符串的最小成本 II 2696
// 2052. 将句子分隔成行的最低成本（会员题）

