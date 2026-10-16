class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = nums[0];
        int ct = 1;
        for (int num : nums){
            if (ct == 0){
                c = num;
            }
            if (num == c){
                ct++;
            }else{
                ct--;
            }
        }
        return c;
    }
};