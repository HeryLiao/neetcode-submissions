class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> inDegree;

        for (const string& word : words){
            for (char c : word){
                inDegree[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDiff = false;
            for (int j = 0; j < len; j++){
                if (w1[j] != w2[j]){
                    char c1 = w1[j], c2 = w2[j];
                    if (adj[c1].find(c2) == adj[c1].end()){
                        adj[c1].insert(c2);
                        inDegree[c2]++;
                    }
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && w1.size() > w2.size()){
                return "";
            }
        }
        queue<char> q;
        for (auto& [c, degree] : inDegree){
            if(degree == 0){
                q.push(c);
            }
        }

        string result = "";
        while (!q.empty()){
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]){
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        if (result.size() < inDegree.size()){
            return "";
        }
        return result;
    }
};
