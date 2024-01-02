
#include <vector>
#include <stack>

using namespace std;

vector<int> monotonicStack(vector<int> &prices){
// copy array for results
    vector<int> result(prices.begin(), prices.end());
    // monotonic stack (store index)
    stack<int> monotonic;
    for (int i = 0; i < prices.size(); i++) {
    // make sure stack is not empty and the elements inside is monotonically increasing.
    // If new element is smaller, then start pop
    while (!monotonic.empty() && prices[monotonic.top()] >= prices[i] ) {
        result[monotonic.top()] = prices[monotonic.top()] - prices[i];
        monotonic.pop();
    }
    monotonic.push(prices[i]);
    }
}
// Time complexity: O(n)
// Space complexity: O(n)

// Example: LintCode 1852