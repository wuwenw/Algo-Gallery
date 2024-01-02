class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left <= right) {
            int pivot = left + rand() % (right - left + 1);
            pivot = partition(nums, left, right, pivot);
            if (pivot == k) return nums[pivot];
            else if (pivot < k) {
                return quickSelect(nums, pivot + 1, right, k);
            } else {
                return quickSelect(nums, left, pivot - 1, k);
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int left, int right, int pivot) {
        int pivot_val = nums[pivot];
        swap(nums[right], nums[pivot]);
        int stored_index = left;
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot_val) {
                swap(nums[stored_index], nums[j]);
                stored_index++;
            }
        }
        swap(nums[stored_index], nums[right]);
        return stored_index;
    }
    
};

// stl built in funtion nth_element
// nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
// kth largest num is at nums[k - 1];
// uses Introselect to combine quick select and heap sort

// stl built in function partial_sort
// partial_sort(s.begin(), s.begin() + k, s.end(), greater<int>());
// kth largest number is at num[k]