class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void backtrack(vector<int>& nums , int target , int currentSum , int startindex){
        if(currentSum == target){
            res.push_back(path);
            return;
        }
        if(currentSum > target){
            return;
        }
        for(int i = startindex ; i < nums.size() ; i++){
            path.push_back(nums[i]);

            backtrack(nums , target , currentSum + nums[i] , i);

            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        path.clear();
        backtrack( nums, target, 0, 0);
        return res;
    }
};
