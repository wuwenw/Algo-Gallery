// https://leetcode.com/problems/count-special-integers/
// note that mask and is_num(depended on leading zero) may not be necessary
class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        int len = s.size();
        vector<vector<int>> memo(len, vector<int>(1 << 10, -1));
        function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool is_limit, bool is_num) {
            if (i == len)
                return static_cast<int>(is_num);
            if (!is_limit && is_num && memo[i][mask] != -1)
                return memo[i][mask];
            int res = 0;
            // if prev is not a number, try skip i
            if (!is_num)
                res = dfs(i + 1, mask, false, false);
            // if prev is not a number, num[i] has to be 1 to form a number
            int low = is_num ? 0 : 1;
            int high = is_limit ? s[i] - '0' : 9;

            for (int j = low; j < high + 1; j++) {
                // check if j th bit is in the mask
                if (((mask >> j) & 1) == 0)
                    res += dfs(i + 1, mask | (1 << j), is_limit && j == high, true);
            }
            // results for is_limit and !is_num will not be cached
            if (!is_limit && is_num)
                memo[i][mask] = res;

            return res;
        };
        return dfs(0, 0, true, false);
    }
};

// https://leetcode.com/problems/number-of-digit-one/
class Solution {
public:
    int countDigitOne(int n) {
        auto s = to_string(n);
        int len = s.size();

        vector<vector<int>> memo(len, vector<int>(len, -1));
        function<int(int, int, bool)> dfs = [&](int i, int count, bool is_limit) {
            if (i == len)
                return count;
            if (!is_limit && memo[i][count] != -1)
                return memo[i][count];
            int high = is_limit? s[i] - '0' : 9;

            int res = 0;
            for (int d = 0; d <= high; d++) {
                res += dfs(i + 1, count + (d == 1), is_limit && d == high);
            }

            if (!is_limit)
                memo[i][count] = res;

            return res;
        };

        return dfs(0, 0, true);
    }
};

// https://leetcode.com/problems/numbers-with-repeated-digits/

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int len = s.size();
        vector<vector<int>> memo(len, vector<int>(1 << 10, -1));

        function<int(int, int, bool)> dfs = [&](int i, int mask, bool is_limit) {
            if (i == len)
                return static_cast<int>(mask != 0);
            if (!is_limit && memo[i][mask] != -1)
                return memo[i][mask];
            int res = 0;
            if (mask == 0)
                res = dfs(i + 1, mask, false);
            int low = mask == 0 ? 1 : 0;
            int high = is_limit ? s[i] - '0' : 9;
            for (int d = low; d <= high; d++) {
                if (((mask >> d) & 1) == 0)
                    res += dfs(i + 1, mask | (1 << d), is_limit && d == high);
            }
            if (!is_limit && mask != 0)
                memo[i][mask] = res;
            return res;
        };

        return n - dfs(0, 0, true);
    }
};

// positive direction
class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        auto s = to_string(n);
        int len = s.size();
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(1 << 10, vector<int>(2, -1)));
        function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool is_limit, bool is_repeat) {
            if (i == len) {
                return (int)(is_repeat && mask != 0);
            }
            if (!is_limit && mask != 0 && memo[i][mask][is_repeat] != -1)
                return memo[i][mask][is_repeat];
            int res = 0;
            if (mask == 0)
                res = dfs(i + 1, 0, false, false);
            
            int low = mask != 0 ? 0 : 1;
            int high = is_limit ? s[i] - '0' : 9;
            for (int d = low; d <= high; d++) {
                res += dfs(i + 1, mask | (1 << d), is_limit && d == high, is_repeat || ((mask >> d) & 1));
            }
            if (!is_limit && mask != 0)
                memo[i][mask][is_repeat] = res;
            return res;
        };
        return dfs(0, 0, true, false);
    }
};
