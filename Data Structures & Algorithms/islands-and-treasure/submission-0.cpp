class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int , int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 2147483647){
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};
