class Solution {
private:
    vector<vector<int>> dp;
    int dfs(int i, int j, string& s, string& t){
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]){
            dp[i][j] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        }else{
            dp[i][j] = dfs(i + 1, j, s, t);
        }
        return dp[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return dfs(0, 0, s, t);
    }
};
