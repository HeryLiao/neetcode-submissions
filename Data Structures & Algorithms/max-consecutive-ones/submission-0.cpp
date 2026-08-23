class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_1= 0;
        int temp = 0;
        for(int a : nums){
            if(a == 1){
                temp++;
                max_1 = max (max_1 , temp);
            }
            else{
                temp = 0;
            }
        }
        return max_1;
    }
};