using ull = unsigned long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}
int mod1 = 998244353 + rnd(0, 1e9), base1 = 131 + rnd(0, 1e3);
int mod2 = 1000577 + rnd(0, 1e9), base2 = 53 + rnd(0, 1e3);
struct StringHash {
    vector<ull> h1, h2, p1, p2;
    StringHash(const string &s) {
        int n = s.size();
        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base1 + s[i]) % mod1;
            h2[i + 1] = (h2[i] * base2 + s[i]) % mod2;
            p1[i + 1] = p1[i] * base1 % mod1;
            p2[i + 1] = p2[i] * base2 % mod2;
        }
    }
    pair<ull, ull> get(int l, int r) {
        return {(h1[r + 1] - h1[l] * p1[r - l + 1] % mod1 + mod1) % mod1,
                (h2[r + 1] - h2[l] * p2[r - l + 1] % mod2 + mod2) % mod2};
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        map<pair<ull, ull>, int> cnts;
        ull res = 0;
        for (const auto& word: words) {
            auto sh = StringHash(word);
            int m = word.size();
            for (int i = 1; i <= m; i++) {
                auto prefix = sh.get(0, i - 1);
                if (prefix == sh.get(m - i, m - 1)) {
                    if (cnts.contains(prefix)) {
                        res += cnts[prefix];
                    }
                }
            }
            cnts[sh.get(0, m - 1)]++;
        }
        return res;
    }
};
