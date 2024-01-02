#include <vector>
using namespace std;

vector<int> sortArray(vector<int>& nums) {
    for (int i = nums.size() / 2 - 1; i >=0; i--)
    {
        // heapify from back
        maxHeapify(nums, nums.size(), i);
    }
    
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        // heapify from the begining
        // size reduces by 1 every iteration
        maxHeapify(nums, i, 0);
    }
    
    return nums;
}

void maxHeapify(vector<int>& nums, int size, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < size && nums[left] > nums[largest])
        largest = left;
    if (right < size && nums[right] > nums[largest])
        largest = right;
    if (largest != index)
    {
        swap(nums[largest], nums[index]);  
        maxHeapify(nums, size, largest);
    }
}
