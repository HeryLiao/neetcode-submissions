class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq = 0;
        unordered_map<char , int> con;
        for(auto a : tasks){
            con[a]++;
            maxFreq = max (maxFreq , con[a]);
        }
        int maxCount = 0 ;
        for(const auto&a : con){
            if(a.second == maxFreq) maxCount++;
        }
        return max((maxFreq - 1) * (n + 1) + maxCount ,(int)tasks.size());
    }
};
