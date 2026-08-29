class Solution {
private:
    vector<string> res;
    string path;

    void backtrack(int n, int left, int right){

        if(left == n && right == n){
            res.push_back(path);
            return;
        }
        if(left < n){
            path.push_back('(');
            backtrack(n , left + 1, right);
            path.pop_back();
        }
        if(left > right){
            path.push_back(')');
            backtrack(n , left, right + 1);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        path = "";
        backtrack(n, 0, 0);
        return res;
    }
};
