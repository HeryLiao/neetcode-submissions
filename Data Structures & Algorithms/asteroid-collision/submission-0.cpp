class Solution {

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int ast : asteroids){
            while (!ans.empty() && ast < 0 && ans.back() > 0){
                if (ans.back() < -ast){
                    ans.pop_back();
                }else if (ans.back() == -ast){
                    ans.pop_back();
                    ast = 0;
                    break;
                }else{
                    ast = 0;
                    break;
                }
            }
            if (ast != 0){
                ans.push_back(ast);
            }
        }
        return ans;
    }
};