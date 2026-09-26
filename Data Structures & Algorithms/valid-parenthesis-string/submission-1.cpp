class Solution {
public:
    bool checkValidString(string s) {
        int min_l = 0;
        int max_l = 0;
        for (char c : s){
            if (c == '('){
                min_l++;
                max_l++;
            }
            else if (c == ')'){
                min_l--;
                max_l--;
            }
            else if (c == '*'){
                min_l--;
                max_l++;
            }
            if (max_l < 0) return false;
            if (min_l < 0) min_l = 0;
        }
        return min_l == 0 ;
    }
};
