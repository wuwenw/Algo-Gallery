class Solution {
public:
    int maximumSum(string input) {
        int n = input.size();
        
        auto dp = [&](dp())
    }
};

// dp(i, j) = max(dp(i - 1, j), dp(i - 1, j - 1) + getreduced(1), ..., dp(i - 1, max(0, j - k)) + reduced(min(j, k)))