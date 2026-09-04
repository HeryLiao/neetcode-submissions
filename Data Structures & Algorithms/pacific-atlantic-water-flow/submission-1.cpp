class Solution {
private:
    vector<vector<int>> res;
    int m, n;
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& ocean){
        ocean[r][c] = true;

        for (auto& dir : dirs){
            int nr = r + dir.first;
            int nc = c + dir.second;

            if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;

            if(ocean[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
            dfs(heights, nr, nc, ocean);
        }
    }
public:
     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //pacific [0][0]~[0][4] + [1][0] + [2][0]
        //atlantic [0][4] + [1][4] + [2][4] + [2][0]~[2][4]
        // m x n = p [0][0]~[0][n-1] + [1][0]~[m-1][0]
        // a = [0][n-1] ~ [m-1][n-1] + [m-1][0]~[m-1][n-1]
        if (heights.empty() || heights[0].empty()) return {};
        m = heights.size();
        n = heights[0].size();
        res.clear();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> altantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++){
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, altantic);
        }
        for (int j = 0; j < n; j++){
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, altantic);
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (pacific[i][j] && altantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
