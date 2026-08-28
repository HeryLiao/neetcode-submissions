class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for(int num : nums){
            int currentSize = res.size();

            for(int i = 0 ; i < currentSize ; i++){
                vector<int> newSubset = res[i];
                newSubset.push_back(num);
                res.push_back(newSubset);
            }
        }
        return res;
    }
};
