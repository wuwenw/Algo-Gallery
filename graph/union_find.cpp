
// https://leetcode.com/problems/number-of-provinces/

class Solution {
    struct UnionSet
    {
        unordered_map<int, int> parent;
        int num_city = 0;

        void add(int x)
        {
            if (parent.count(x) == 0)
            {
                parent[x] = -1;
                ++num_city;
            }
        }

        int find(int x)
        {   
            if (parent.find(x) == parent.end())
                return -1;
            // x is not the root
            int root = x;
            while (parent[root] != -1)
                root = parent[root];
            while (x != root)
            {
                int original = parent[x];
                parent[x] = root;
                x = original;
            }
            return root;
        }

        void merge(int x, int y)
        {
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y)
            {
                parent[root_x] = root_y;
                --num_city;
            }
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionSet us;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            for (int j = 0; j < isConnected[0].size(); ++j)
            {
                if (isConnected[i][j])
                {
                    us.add(i);
                    us.add(j);
                    us.merge(i, j);
                }
            }
        }
        
        return us.num_city;
    }
};
