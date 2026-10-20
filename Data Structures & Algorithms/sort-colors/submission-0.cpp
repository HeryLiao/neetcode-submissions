class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int j = n - 1 ; j > 0; j--){
            int cur = -1;
            int cur_i = 0;
            for (int i = 0; i <= j; i++){
                if (nums[i] > cur){
                    cur = nums[i];
                    cur_i = i;
                }
            }
            swap(nums[j], nums[cur_i]);
        }
    } 
};