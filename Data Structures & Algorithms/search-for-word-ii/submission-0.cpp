class Solution {

private:

    vector<string> res;

    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        string word = "";
    };

    TrieNode* root;

    void insert(const string& word){
        TrieNode* curr = root;
        for (char c : word){
            int idx = c - 'a';
            if (curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }


    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node){
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        char ch = board[r][c];
        if (ch == '#' || node->children[ch - 'a'] == nullptr) return;

        node = node->children[ch - 'a'];

        if (node->word != ""){
            res.push_back(node->word);
            node->word = "";
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, node);
        dfs(board, r - 1, c, node);
        dfs(board, r, c + 1, node);
        dfs(board, r, c - 1, node );

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        res.clear();
        
        for (const string& w : words){
            insert(w);
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                dfs(board, i, j, root);
            }
        }
        return res;
    }
};
