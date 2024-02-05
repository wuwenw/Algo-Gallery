// https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<char, int> t_freqs;
        unordered_map<char, int> s_freqs;
        int count = 0, left = 0;
        int res_left = 0, len = INT_MAX;
        for (char c: t) {
            t_freqs[c]++;
        }
        int n = t_freqs.size();
        for (int right = 0; right < s.size(); right++) {
            if (!t_freqs.contains(s[right]))
                continue;
            char c = s[right];
            s_freqs[c]++;
            count += t_freqs[c] == s_freqs[c];

            while (count == t_freqs.size()) {
                char lc = s[left];
                --s_freqs[lc];
                // if move left makes unmatch, then we calculate result
                if (t_freqs.contains(lc)&& s_freqs[lc] < t_freqs[lc]) {
                    count--;
                    if (right - left + 1 < len) {
                        len = right - left + 1;
                        res_left = left;
                    }
                }
                ++left;
            }
        }
        return len == INT_MAX ? "" : s.substr(res_left, len);
    }
};
