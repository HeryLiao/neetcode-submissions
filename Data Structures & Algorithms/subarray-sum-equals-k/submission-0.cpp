class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            int cur = 0;
            for (int j = i; j < nums.size(); j++){
                cur += nums[j];
                if (cur == k) ans++;
            }
        }
        return ans;
    }
};