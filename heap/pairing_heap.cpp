// https://leetcode.com/problems/find-median-from-data-stream/description/
class MedianFinder {
    // max heap
    priority_queue<int> left;
    // min heap
    priority_queue<int, vector<int>, greater<int>> right;
    double median;
public:
    MedianFinder(): median(0) {
        
    }
    
    void addNum(int num) {
        if (left.size() == right.size()) {
            if (!left.empty() && num < left.top()) {
                left.push(num);
                num = left.top();
                left.pop();
            }
            right.push(num);
            median = right.top();
        }
        else {
            if (num > right.top()) {
                right.push(num);
                num = right.top();
                right.pop();
            }
            left.push(num);
            median = ((double)left.top() + right.top()) / 2;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// using AVL tree (self balanced tree) -> nlog(n)
// better than pq 5nlog(n)
class MedianFinder {
    multiset<int> mt;
    multiset<int>::iterator low_median, high_median;
public:
    MedianFinder()
        :low_median(mt.end())
        ,high_median(mt.end()) {
        
    }
    
    void addNum(int num) {
        int n = mt.size();
        mt.insert(num);
        if (n == 0) {
            low_median = mt.begin();
            high_median = mt.begin();
        }
        else if (n & 1) {
            if (num < *low_median)
                --low_median;
            else
                ++high_median;
        }
        else {
            if (num > *low_median && num < *high_median) {
                ++low_median;
                --high_median;
            }
            else if (num >= *high_median) {
                ++low_median;
            }
            else {
                low_median = --high_median;
            }
        }

    }
    
    double findMedian() {
        return ((double) *low_median + *high_median) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
