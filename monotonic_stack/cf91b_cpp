// monostack + binary search
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> CF91B(int n, vector<int>& nums) {
    vector<int> st;
    vector<int> res(n);
    auto comp = [&nums](int a, int b) {
        return nums[a] > nums[b];
    };
    for (int i = n - 1; i >= 0; i--) {
        auto it = upper_bound(st.begin(), st.end(), i, comp);
        if (it != st.end())
            res[i] = *it - i - 1;
        else
            res[i] = -1;
        if (st.empty() || nums[i] < nums[st.back()])
            st.push_back(i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }

    // Your logic here
    vector<int> result = CF91B(n, nums);
    for (int r : result) {
        cout << r << " ";
    }
    cout << "\n";
}
