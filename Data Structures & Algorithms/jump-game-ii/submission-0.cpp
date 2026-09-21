class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        int min_step = 0;
        int current_end = 0;
        int max_len = 0;
        for (int i = 0; i < n - 1; i++){
            max_len = max(max_len, i + nums[i]);
            if (i == current_end){
                min_step++;
                current_end = max_len;
                if (current_end >= n - 1){
                    break;
                }
            }
        }
        return min_step;
    }
};
