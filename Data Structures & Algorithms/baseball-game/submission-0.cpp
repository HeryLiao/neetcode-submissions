class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ops;
        for (int i = 0; i < operations.size(); i++){
            if (operations[i] == "+" && ops.size() > 1){
                int n = ops.size();
                int temp = ops[n - 1];
                int temp2 = ops[n - 2];
                ops.push_back(temp + temp2);
            }else if (operations[i] == "C" && ops.size() > 0){
                ops.pop_back();
            }
            else if (operations[i] == "D" && ops.size() > 0){
                int temp = ops.back();
                ops.push_back(temp * 2);
            }else{
                ops.push_back(stoi(operations[i]));
            }
            
        }
        int ans = 0;
        for (int j = 0; j < ops.size(); j++){
            ans += ops[j];
        }
        return ans;
    }
};