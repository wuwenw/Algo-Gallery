// https://leetcode.com/problems/path-with-minimum-effort/

#include <vector>
#include <queue>
#include <climits>

class Solution {
    struct PathState {
        int row;
        int col;
        int effort;
        PathState(int r, int c, int e) : row(r), col(c), effort(e) {}
    };

    struct ComparePathState {
        bool operator()(const PathState& a, const PathState& b) {
            return a.effort > b.effort;
        }
    };

    const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> diffs(rows, vector<int>(cols, INT_MAX));
        diffs[0][0] = 0;

        priority_queue<PathState, vector<PathState>, ComparePathState> pq;
        pq.emplace(0, 0, 0);

        while (!pq.empty()) {
            PathState cur = pq.top();
            pq.pop();
            if (visited[cur.row][cur.col]) continue;
            visited[cur.row][cur.col] = true;

            if (cur.row == rows - 1 && cur.col == cols - 1) {
                return cur.effort;
            }

            for (const auto& direction : directions) {
                int next_row = cur.row + direction[0];
                int next_col = cur.col + direction[1];
                if (isValid(next_row, next_col, rows, cols)) {
                    int cur_diff = abs(heights[next_row][next_col] - heights[cur.row][cur.col]);
                    int max_diff = max(diffs[cur.row][cur.col], cur_diff);
                    if (max_diff < diffs[next_row][next_col]) {
                        diffs[next_row][next_col] = max_diff;
                        pq.emplace(next_row, next_col, max_diff);
                    }
                }
            }
        }
        return diffs[rows - 1][cols - 1];
    }

    bool isValid(int i, int j, int rows, int cols) {
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }
};
