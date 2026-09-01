class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    
    bool isPalidrome(const string& s, int startIndex, int endIndex){
        while(startIndex < endIndex){
            if(s[startIndex] != s[endIndex]){
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }

    void backtrack(const string& s, int startIndex){
        
        if(startIndex == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if(isPalidrome(s, startIndex, i)){
                string sub = s.substr(startIndex, i - startIndex + 1);
                path.push_back(sub);

                backtrack(s, i + 1);

                path.pop_back();
            }
        }


    }

public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        res.clear();
        path.clear();
        backtrack(s, 0);
        return res;
    }
};
