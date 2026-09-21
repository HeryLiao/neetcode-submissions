class Solution {
private:
    vector<int> dp;
    bool dfs(int i, vector<int>& nums){
        if (i >= nums.size() - 1) return true;
        if (dp[i] != -1) return dp[i];
        for (int step = 1; step <= nums[i]; step++){
            if (dfs(i + step, nums)){
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int> (n , -1);
        return dfs(0, nums);
    }
};
