class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;//this round rotting fruit
        int fresh_count = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2){
                    q.push({i, j});
                }else if (grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int minutes = 0;

        while (!q.empty() && fresh_count > 0){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs){
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc] != 1){
                        continue;
                    }

                    grid[nr][nc] = 2;
                    fresh_count--;
                    q.push({nr, nc});
                
                }
            }
            minutes++;
        }
        return fresh_count == 0 ? minutes : -1;
    }
};
