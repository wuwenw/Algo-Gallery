#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// To be used as a member variable
struct cmp {
    bool operator () (const int a,const int b)const {
        // Default big root heap, so we can sort by frequency from small to large and time stamp from small to large
        return a < b;
    }
};

// only valid after c++20
auto f(auto &map) {
    return map[make_pair(0,0)];
}

template<typename hashT>
auto f1(unordered_map<pair<int, int>, int, hashT> &map) {
    return map[make_pair(0,0)];
}

template<typename mapT>
auto f2(mapT &map) {
    return map[make_pair(0,0)];
}

int main()
{
    // 1,2,3
    // a > b => 1,2,3 => greater<int> => minHeap
    // a < b => 3,2,1 => less<int> => maxHeap
    auto comp = [](int &a, int &b) {
        return a > b;
    };
    
    priority_queue<int, vector<int>, decltype(comp)> pq(comp);
    priority_queue<int, vector<int>, cmp> pq1(cmp);

    auto userHash = [](const pair<int, int> &a) {
            return hash<int>{}(a.first) ^ hash<int>{}(a.second);
        };
        
    unordered_map<pair<int, int>, int, decltype(userHash)> m(0, userHash);
    
    m[make_pair(0,0)] = 1;
    cout << f(m) << endl;;
    cout << f1(m) << endl;;
    cout << f2(m) << endl;;

    return 0;
}


class foo{
    unordered_map<int, vector<int>> valToFreq;
    
    struct cmp {
        bool operator () (const int a,const int b) const {
            if ((*valToFreq)[a][0] == (*valToFreq)[b][0]) {
                return (*valToFreq)[a].back() > (*valToFreq)[b].back();
            } 
            return (*valToFreq)[a][0] < (*valToFreq)[b][1];
    }
       unordered_map<int, vector<int>> *valToFreq;
};
    
    priority_queue<int, vector<int>, cmp> pq(cmp(&valToFreq));
};