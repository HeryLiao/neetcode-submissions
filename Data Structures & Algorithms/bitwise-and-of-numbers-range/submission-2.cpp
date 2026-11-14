class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left > right) return 0;
        int ans = left;
       for (int i = left + 1 ; i <= right; i++){
            ans = ans & i;
       }
        return ans;
    }
};