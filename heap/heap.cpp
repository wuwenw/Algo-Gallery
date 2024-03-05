#include <vector>
using namespace std;

class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> &input) { heap = buildHeap(input); }

  vector<int> buildHeap(vector<int> &input) {
    int n = input.size();
    int parent = (n - 2)/2;
    for(int i = parent; i >= 0; i--) {
      siftDown(i, n - 1, input);
    }
    
    return input;
  }

  void siftDown(int current, int end, vector<int> &heap) {
    int left = current * 2 + 1;
    int right = current * 2 + 2;
    int swap_index = current;
    if (left <= end && heap[left] < heap[swap_index]) {
      swap_index = left;
    }

    if (right <= end && heap[right] < heap[swap_index]) {
      swap_index = right;
    }

    if (swap_index != current) {
      swap(heap[swap_index], heap[current]);
      siftDown(swap_index, end, heap);
    }
    
  }

  void siftUp(int current, vector<int> &heap) {
    if (current <= 0 ) return;
    int parent = (current - 1) / 2;
    if (heap[current] < heap[parent]) {
      swap(heap[current], heap[parent]);
      current = parent;
      siftUp(current, heap);
    }
    
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    swap(heap[0], heap[heap.size() - 1]);
    int removed = heap.back();
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    return removed;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }
};
