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
    // find all occurrence of pattern s in text t
    vector<int> rabin_karp(string const& s, string const& t) {
        int n = t.size();
        int m = s.size();
        vector<int> res;
        auto sh = StringHash(t);
        auto s_hash = StringHash(s).get(0, m - 1);
        for (int i = 0; i <= n - m; i++) {
            auto t_hash = sh.get(i, i + m - 1);
            if (t_hash == s_hash)
                res.push_back(i);
        }
        return res;
    }
};
