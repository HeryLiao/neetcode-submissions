class Solution {
private:
    vector<vector<int>> dp;
    
    bool dfs(int i, int j, string& s, string& p){
        if (j == p.length()){
            return i == s.length();
        }
        if (dp[i][j] != -1) return dp[i][j];

        bool first_match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        bool ans = false;

        if (j + 1 < p.length() && p[j + 1] == '*'){
            ans = dfs(i, j + 2, s, p) || (first_match && dfs(i + 1, j, s, p));
        }else{
            ans = first_match && dfs(i + 1, j + 1, s, p);
        }
        return dp[i][j] = ans;
        
        }
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, s, p);
    }
};
