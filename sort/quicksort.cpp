class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }

    int partition(vector<int> &array, int low, int high, int pivot) {
        int pivot_val = array[pivot];
        swap(array[high], array[pivot]);
        int i = low;
        for (int j = low; j < high; j++) {
            if (array[j] < pivot_val) {
                swap(array[i], array[j]);
                i++;
            }
        }
        swap(array[i], array[high]);
        return i;
    }

    void quickSortHelper(vector<int> &array, int low, int high) {
        if (low < high) {
            int pivot = low + rand() % (high - low + 1);
            pivot = partition(array, low, high, pivot);
            quickSortHelper(array, low, pivot - 1);
            quickSortHelper(array, pivot + 1, high);
        }
    }

};