// https://leetcode.com/problems/longest-well-performing-interval/description/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n + 1);
        stack<int> st;
        int res = 0;
        // for increasing intervals in the begining
        st.push(0);
        for (int i = 1; i <= n; i++) {
            int time = hours[i - 1] > 8 ? 1 : -1;
            prefix[i] = prefix[i - 1] + time;
            if (prefix[i] < prefix[st.top()]) st.push(i);
        }

        for (int i = n; i > 0; i--) {
            while (!st.empty() && prefix[i] > prefix[st.top()]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};
