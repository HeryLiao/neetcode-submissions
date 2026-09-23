class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0;
        int current_tank = 0;
        int start_tank = 0;
        for (int i = 0; i < n; i++){
            int net = gas[i] - cost[i];
            total_tank += net;
            current_tank += net;
            if (current_tank < 0){
                start_tank = i + 1;
                current_tank = 0;
            }
        }
        return total_tank >= 0 ? start_tank : -1;
    }
};
