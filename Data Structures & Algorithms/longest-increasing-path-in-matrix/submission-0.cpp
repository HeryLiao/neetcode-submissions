class Solution {
private:
    int m,n;
    vector<vector<int>> dp;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int r, int c, vector<vector<int>>& matrix){
        if (dp[r][c] != 0) return dp[r][c];

        int max_len = 1;
        for (auto& dir: dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]){
                max_len = max(max_len, 1 + dfs(nr, nc, matrix));
            }
        }
        return dp[r][c] = max_len;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        m = matrix.size();
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};
