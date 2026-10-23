class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size() / 3;
        vector<int> ans;
        unordered_map<int, int> counts;
        for (auto n : nums){
            counts[n]++;
        }
        for (auto pair : counts){
            if (pair.second > n){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};