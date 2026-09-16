class Solution {
private:
    vector<vector<int>> dp;
    int dfs(int i, int amount, vector<int>& coins){
        if (amount == 0) return 1;
        if (amount < 0 || i >= coins.size()) return 0;

        if (dp[i][amount] != -1) return dp[i][amount];
        dp[i][amount] = dfs(i, amount - coins[i], coins) + dfs(i + 1, amount, coins);
        return dp[i][amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp = vector<vector<int>>(n, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }
};
