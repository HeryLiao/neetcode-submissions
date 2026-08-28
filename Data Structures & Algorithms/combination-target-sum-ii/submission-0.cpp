class Solution {
private:
    vector<vector<int>>res;
    vector<int>path;

    void backtrack(vector<int>& candidates, int target, int currentSum, int startIndex){
        if(currentSum == target){
            res.push_back(path);
            return;
        }
        for(int i = startIndex ; i < candidates.size() ; i++){
            if(currentSum + candidates[i] > target){
                break;
            }
            if(i > startIndex && candidates[i] == candidates[i - 1]){
                continue;
            }
            path.push_back(candidates[i]);
            backtrack(candidates , target , currentSum + candidates[i] , i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        sort(candidates.begin() , candidates.end());
        backtrack( candidates, target, 0, 0);
        return res;
    }
};
