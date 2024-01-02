// https://leetcode.com/problems/can-make-palindrome-from-substring/description/
// Use xor to optimize
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> res(queries.size());
        vector<vector<int>> sums(n + 1, vector<int>(26));
        for (int i = 0; i < n; i++)
        {
            sums[i + 1] = sums[i];
            // freq of char at s[i] ++
            sums[i + 1][s[i] - 'a']++;
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0], right = queries[i][1], k = queries[i][2];
            int m = 0;
            for (int j = 0; j < 26; j++)
                // count odd freqs of char within this range
                // even freqs can be re-arranged
                m += (sums[right + 1][j] - sums[left][j]) % 2;

            // for odd freq chars, only half of them needs to be transformed
            // a b b c -> only change a
            res[i] = m / 2 <= k;
        }
        return res;
    }
};
