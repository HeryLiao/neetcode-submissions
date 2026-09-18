class Solution {
private:
    vector<vector<int>> dp;
    bool dfs(int i, int j, string& s1, string& s2, string& s3){
        if (i == s1.length() && j == s2.length()) return true;
        if (dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        int k = i + j;
        if (i < s1.length() && s1[i] == s3[k]){
            ans = ans || dfs(i + 1, j, s1, s2, s3);
        }
        if (j < s2.length() && s2[j] == s3[k]){
            ans = ans || dfs(i ,j + 1, s1, s2, s3);
        }
        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        dp = vector<vector<int>>(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return dfs(0, 0, s1, s2, s3);
    }
};
