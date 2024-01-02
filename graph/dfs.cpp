class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> visited(grid);
        int island = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == '1')
                {
                    dfs(visited, i, j);
                    island++;
                }
            }
        }
        return island;
    }

    void dfs(vector<vector<char>> &visited, int i, int j)
    {   
        if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size())
            return;
        if (visited[i][j] == '0')
            return;
        
        visited[i][j] = '0';
        dfs(visited, i + 1, j);
        dfs(visited, i, j + 1);
        dfs(visited, i - 1, j);
        dfs(visited, i, j - 1);
    }
};

// https://leetcode.com/problems/number-of-islands/
