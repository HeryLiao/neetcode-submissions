class Solution {
private:
    map<pair<int, int>, int> dp;
    int dfs(int i, int current_sum, int target, vector<int>& nums){
        if (i == nums.size()){
            return current_sum == target ? 1 : 0;
        }
        if (dp.count({i, current_sum})){
            return dp[{i, current_sum}];
        }
        int add = dfs(i + 1, current_sum + nums[i], target, nums);
        int sub = dfs(i + 1, current_sum - nums[i], target, nums);
        dp[{i, current_sum}] = add + sub;
        return dp[{i, current_sum}];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return dfs(0, 0, target, nums);
    }
};
