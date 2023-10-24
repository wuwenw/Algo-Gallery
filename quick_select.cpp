class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left <= right) {
            int pivot = partition(nums, left, right);
            if (pivot == k) return nums[pivot];
            else if (pivot < k) {
                return quickSelect(nums, pivot + 1, right, k);
            } else {
                return quickSelect(nums, left, pivot - 1, k);
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right) {
        int pivotIndex = right;
        int i = left;
        for (int j = left; j <= right; j++) {
            if (nums[j] < nums[pivotIndex]) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[pivotIndex]);
        return i;
    }
    
};