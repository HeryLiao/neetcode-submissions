class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = n & 0xFFFFFFFF;
        int ans = 0;
        while(n > 0){
            if(n & 1)ans++;
            n = n >> 1;
        }
        return ans;
    }
};
