class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int ans = nums[0];
        for(int i = 0; i < nums.size(); i++){
            curSum = max (nums[i] , curSum + nums[i]);
            ans = max (ans, curSum);
        }

        return ans;
    }
};
