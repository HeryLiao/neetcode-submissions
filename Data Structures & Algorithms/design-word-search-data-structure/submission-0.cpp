class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for (int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;

    bool dfs(const string& word, int index, TrieNode* node){
        if (index == word.size()){
            return node->isEnd;
        }
        char c = word[index];
        if (c == '.'){
            for (int i = 0; i < 26; i++){
                if (node->children[i] != nullptr){
                    if(dfs(word, index + 1,node->children[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            int childIdx = c - 'a';
            if (node->children[childIdx] == nullptr){
                return false;
            }
            return dfs(word, index + 1, node->children[childIdx]);
        }
        
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word){
            int idx = c - 'a';
            if (curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0,root);
    }
};
