class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> current = intervals[0];
        for (int i = 0; i < intervals.size(); i++){
            if (intervals[i][0] <= current[1]){
                current[1] = max(current[1], intervals[i][1]);
            }
            else{
                res.push_back(current);
                current = intervals[i];
            }
        }
        res.push_back(current);
        return res;
    }
};
