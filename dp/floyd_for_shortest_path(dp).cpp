// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
    int floyedTopDown(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n)));

        // init graph with gven weights
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        function<int(int, int, int)> dp = [&](int k, int i, int j) {
            // if intermediate node k is smaller than 0
            // return condition
            if (k < 0)
                return dist[i][j];

            auto &res = memo[k][i][j];
            // calculated before
            if (res)
                return res;
            
            // the shortest path from i to j is either
            // 1. a path from i to j that doesn't contain k -> go to k - 1
            // 2. a path from i to k and k to j -> go to sub problems with k - 1
            return res = min(dp(k - 1, i, j), dp(k - 1, i, k) + dp(k - 1, k, j));
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i)
                    dp(n - 1, i, j);
            }
        }
        return -1;
    }

    int floyedBottomUp(int n, vector<vector<int>>& edges) {
        // edges[i] = {from, to, weight}
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> dp(n, vector<int>(n));

        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        dp = dist;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // dp[k + 1][i][k] -> shortest path from i to k
                    // all path nodes <= k and intermediate nodes <= k - 1
                    // dp[k + 1][i][k] = dp[k][i][k] and dp[k + 1][k][j] = dp[k][k][j]
                    // we can reduce the first dimension of k
                    // dp[k + 1][i][j] = min(dp[k][i][j], dp[k][i][k], dp[k][k][j]);
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
                }
            }
        }

        // do more operations...
        return -1;
    }


public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> dp(n, vector<int>(n));

        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        dp = dist;

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
                }
            }
        }

        int min_count = n, min_city = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && dp[i][j] <= distanceThreshold)
                    count++;
            }
            if (count <= min_count) {
                min_city = i;
                min_count = count;
            }
        }
        return min_city;
    }
};

