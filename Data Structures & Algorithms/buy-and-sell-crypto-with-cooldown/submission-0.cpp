class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int dfs(int i, bool buying, vector<int>& prices){
        if (i >= n) return 0;

        if (dp[i][buying] != -1) return dp[i][buying];
        if (buying){
            int buy = dfs(i + 1, false, prices) - prices[i];
            int cooldown = dfs(i + 1, true, prices);
            dp[i][buying] = max(buy, cooldown);
        }else{
            int sell = dfs(i + 2, true, prices) + prices[i];
            int cooldown = dfs(i + 1, false, prices);
            dp[i][buying] = max(sell, cooldown);
        }
        return dp[i][buying];
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));
        return dfs(0, true, prices);
    }
};
