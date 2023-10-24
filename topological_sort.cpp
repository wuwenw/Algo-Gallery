// L = Empty list that will contain the sorted elements
// S = Set of all nodes with no incoming edge

// while S is non-empty do
//     remove a node n from S
//     add n to tail of L
//     for each node m with an edge e from n to m do
//         remove edge e from the graph
//         if m has no other incoming edges then
//             insert m into S

// if graph has edges then
//     return error   (graph has at least one cycle)
// else 
//     return L   (a topologically sorted order)
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Gnode{
  public:
    Gnode(){
        incomingEdge = 0;
    }
    int incomingEdge;
    vector<int> outNodes;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // sorted classes
        vector<int> sorted;
        // candidate classes with no incoming edge
        queue<int> candidates;
        // course -> list of next courses;
        unordered_map<int, Gnode> graph;
        
        buildGraph(graph, prerequisites);
        
        for (auto it = graph.begin(); it != graph.end(); it++) {
            if (it->second.incomingEdge == 0) {
                candidates.push(it->first);
            }
        }
        
        int removedEdges = 0;
        while (!candidates.empty()) {
            auto course = candidates.front();
            candidates.pop();
            
            for (int nextCourse: graph[course].outNodes) {
                graph[nextCourse].incomingEdge--;
                removedEdges++;
                if (graph[nextCourse].incomingEdge == 0) {
                    candidates.push(nextCourse);
                }
            }
        }
        
        if (removedEdges != prerequisites.size()) {
            return false;
        }
        return true;
        
    }
    
    void buildGraph(unordered_map<int, Gnode> &graph, vector<vector<int>>& prerequisites) {
        for (const auto&course: prerequisites) {
            graph[course[1]].outNodes.push_back(course[0]);
            graph[course[0]].incomingEdge++;
        }
    }
};