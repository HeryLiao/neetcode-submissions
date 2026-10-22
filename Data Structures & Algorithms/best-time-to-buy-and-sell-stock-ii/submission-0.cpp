class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices[0];
        int cur_revenue = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] < cur_min){
                cur_min = prices[i];
            }else{
                cur_revenue += prices[i] - cur_min;
                cur_min = prices[i];
            }

        }
        return cur_revenue;
    }
};