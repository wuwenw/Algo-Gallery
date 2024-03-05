#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

vector<int> split(const string& str) {
    istringstream iss(str);
    vector<int> tokens;
    string token;

    // Extract each token and add it to the vector
    while (iss >> token) {
        tokens.push_back(stoi(token));
    }

    return tokens;
}

// O(n)
vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    // left and right of zbox
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        // current index i is within zbox
        if (i <= r) {
            // choose min(matched z, distance to right boundary)
            z[i] = min(z[i - l], r - i + 1);
        }
        // brute force match towards the end
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i;
            r = i + z[i];
            z[i]++;
        }
    }
    return z;
}


void CF432D() {
    string s;
    getline(cin, s);
    int n = s.size();
    vector<int> z = z_function(s);
    vector<int> cnts(n + 2);
    vector<pair<int, int>> res;
    z[0] = n;
    for (int i = n - 1; i >= 0; i--) {
        cnts[z[i]]++;
    };
    for (int i = n; i > 0; i--) {
        cnts[i] += cnts[i + 1];
        if (z[n - i] == i)
            res.emplace_back(i, cnts[i]);
    }
    cout << res.size() << " " << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i].first << " " << res[i].second << endl;
    }   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    CF432D();
    return 0;
}
