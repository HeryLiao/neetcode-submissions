class Solution {
private:
    vector<vector<int>> dp;
    int dfs(int L, int R, vector<int>& A){
        if (L + 1 >= R) return 0;
        if (dp[L][R] != -1) return dp[L][R];
        int max_coins = 0;
        for (int k = L + 1; k < R; k++){
            int current = A[L] * A[k] * A[R];
            int left_part = dfs(L, k, A);
            int right_part = dfs(k, R, A);
            max_coins = max(max_coins, left_part + right_part + current);
        }
        return dp[L][R] = max_coins;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> A(n + 2);
        A[0] = 1;
        A[n + 1] = 1;
        for (int i = 0; i < n; i++){
            A[i + 1] = nums[i];
        }
        dp = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));

        return dfs(0, n + 1, A);
    }
};
