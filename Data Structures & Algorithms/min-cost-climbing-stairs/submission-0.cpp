class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>rec (n);
        rec[0] = cost[0];
        rec[1] = cost[1];
        for(int i = 2 ; i < n ; i++){
            rec[i] = cost[i] + min(rec[i-1] , rec[i-2]);
        }
        return min(rec[n-1] , rec[n-2]);
        
    }
};
