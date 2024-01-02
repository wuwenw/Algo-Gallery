// hash table and dfs
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int cur_step = 1, max_len = -1;
        vector<int> steps(edges.size(), 0);

        for (int i = 0; i < edges.size(); i++)
        {
            if (steps[i] != 0)
                continue;
            int start = cur_step;
            int cur = i;
            while (cur != -1 && steps[cur] == 0)
            {
                steps[cur] = cur_step++;
                cur = edges[cur];
            }

            // check if cur is visited in this traversal
            if (cur != -1 && steps[cur] >= start)
                max_len = max(max_len, cur_step - steps[cur]);
        }
        return max_len;
    }
};


