class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right)
    {
        vector<int> temp(right - left + 1);
        int left_index = left, right_index = mid + 1, temp_index = 0;

        while(left_index <= mid && right_index <= right)
        {
            if (nums[left_index] <= nums[right_index])
            {
                temp[temp_index++] = nums[left_index++];
            }
            else
            {
                temp[temp_index++] = nums[right_index++];
            }
        }

        // Copy any remaining elements from the left half
        std::copy(nums.begin() + left_index, nums.begin() + mid + 1, temp.begin() + temp_index);

        // Copy any remaining elements from the right half
        std::copy(nums.begin() + right_index, nums.begin() + right + 1, temp.begin() + temp_index);

        // Copy the merged values back into nums
        std::copy(temp.begin(), temp.end(), nums.begin() + left);
    }

    
};