class Solution {
private:
    int m, n;

    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs (vector<vector<char>>& board, int r, int c){
        if (r < 0|| r >= m || c < 0 || c >= n || board[r][c] != 'O'){
            return;
        }
        board[r][c] = 'T';

        for (auto& dir : dirs){
            dfs(board, r + dir.first, c+ dir.second);
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++){
           if (board[i][0] == 'O') dfs(board, i, 0);
           if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
