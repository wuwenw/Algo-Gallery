// https://leetcode.com/problems/course-schedule/

class Solution {
    struct Course {
        int incomings;
        vector<int> outs;
    };

public:
    void buildGraph(vector<vector<int>>& pre, unordered_map<int, Course>& graph) {
        for (auto& prev : pre) {
            graph[prev[1]].outs.emplace_back(prev[0]);
            graph[prev[0]].incomings++;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, Course> graph;
        buildGraph(pre, graph);
        int taken = 0;
        
        queue<int> q;
        for (const auto&course: graph) {
            if (course.second.incomings == 0)
                q.push(course.first);
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            taken++;
            for (int out : graph[cur].outs) {
                graph[out].incomings--;
                if (graph[out].incomings == 0)
                    q.push(out);
            }
        }

        return taken == graph.size();
    }
};
