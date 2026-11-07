class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[s]){
                s++;
                nums[s] = nums[i];
            }
        }
        return s + 1;
    }
};