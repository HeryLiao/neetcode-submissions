class Solution {

private:
    int max_area;
    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs(grid, r + 1, c)
                 + dfs(grid, r - 1, c)
                 + dfs(grid, r, c + 1)
                 + dfs(grid, r, c - 1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        max_area = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1 ){
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
};
