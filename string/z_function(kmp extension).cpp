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
