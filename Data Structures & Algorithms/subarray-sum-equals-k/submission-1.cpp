class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        int prefix_sum = 0;
        int ans = 0;
        for (int num : nums){
            prefix_sum += num;
            if (prefix_counts.find(prefix_sum - k) != prefix_counts.end()){
                ans += prefix_counts[prefix_sum - k];
            }
            prefix_counts[prefix_sum]++;
        }
        return ans;
    }
};