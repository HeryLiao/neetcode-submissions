class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // due to endWord doesn't exist in wordlist 
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while (!q.empty()){
            int sz = q.size();
            
            for (int k = 0; k < sz; k++){
                string curr = q.front();
                q.pop();
                if (curr == endWord) return step;

                for (int i = 0; i < curr.size(); i++){
                    char original = curr[i];

                    for (char c = 'a'; c <= 'z'; c++){
                        if (c == original) continue;
                        curr[i] = c;

                        if (wordSet.find(curr) != wordSet.end()){
                            q.push(curr);
                            wordSet.erase(curr);

                        }
                    }
                    curr[i] = original;

                }
            }
            step++;
        }
        return 0;
    }
};
