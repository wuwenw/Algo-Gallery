#include <vector>
using namespace std;


class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int> &vector) {
    int parentIndex = (vector.size() - 2)/2;
    for(int i = parentIndex; i >= 0; i--) {
      siftDown(i, vector.size() - 1, vector);
    }
    
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    int left = currentIdx * 2 + 1;
    int right = currentIdx * 2 + 2;
    int swapIdx = currentIdx;
    if (left <= endIdx && heap[left] < heap[swapIdx]) {
      swapIdx = left;
    }

    if (right <= endIdx && heap[right] < heap[swapIdx]) {
      swapIdx = right;
    }

    if (swapIdx != currentIdx) {
      swap(heap[swapIdx], heap[currentIdx]);
      siftDown(swapIdx, endIdx, heap);
    }
    
  }

  void siftUp(int currentIdx, vector<int> &heap) {
    if (currentIdx <= 0 ) return;
    int parentIdx = (currentIdx - 1) / 2;
    if (heap[currentIdx] < heap[parentIdx]) {
      swap(heap[currentIdx], heap[parentIdx]);
      currentIdx = parentIdx;
      siftUp(currentIdx, heap);
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
