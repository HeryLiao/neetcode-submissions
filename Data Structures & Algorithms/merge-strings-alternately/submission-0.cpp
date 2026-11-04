class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n = min (word1.size(), word2.size());
        for (int i = 0; i < n; i++){
            ans += word1[i];
            ans += word2[i];
        }
        int p1 = n;
        int p2 = n;
        while (p1 < word1.size()){
            ans += word1[p1];
            p1++;
        }
        while (p2 < word2.size()){
            ans += word2[p2];
            p2++;
        }
        return ans;
    }
};