class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //quick sort
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int left, int right){
        if (left >= right) return;

        int p = randomizedPartition(nums, left, right);
        quickSort(nums, left, p - 1);
        quickSort(nums, p + 1, right);
    }
    int randomizedPartition(vector<int>& nums, int left, int right){
       int randIdx = left + rand() % (right - left + 1);
       swap(nums[randIdx], nums[right]);
       int pivot = nums[right];
       int i = left - 1;
       for (int j = left; j < right; j++){
            if (nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
       }
       swap(nums[i + 1], nums[right]);
       return i + 1; 
    } 
    };