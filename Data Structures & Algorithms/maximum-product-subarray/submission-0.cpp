class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cur_max = nums[0];
        int cur_min = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++){
            int x = nums[i];
            int tempMax = max({x, x * cur_max, x * cur_min});
            cur_min = min({x, x * cur_max, x * cur_min});
            cur_max = tempMax;

            ans = max(ans, cur_max);
        }
        return ans;
    }
};
