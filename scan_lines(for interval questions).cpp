/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        auto comp = [](auto &a, auto &b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };
        // vec[0] -> time, vec[1] -> type: -1 -> start, 1 -> end
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto &scheduleOne : schedule) {
            for (auto &interval : scheduleOne) {
                pq.push({interval.start, -1});
                pq.push({interval.end, 1});
            }
        }
        
        vector<Interval> freeTime;
        int busyCount = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (pq.empty()) {
                break;
            }
            auto next = pq.top();
            
            busyCount += cur[1];
            
            if (cur[1] == 1 && next[1] == -1 && busyCount == 0) {
                freeTime.emplace_back(cur[0], next[0]);
            }
        }
        
        return freeTime;
    }
};