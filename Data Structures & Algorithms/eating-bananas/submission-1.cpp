class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int p : piles){
            right = max (right , p);
        }
        int ans = right ;
        while (left <= right){
            int mid = left + (right -left) /2;
            long long h_n = 0;
            for(int p : piles){
                h_n += (p + mid - 1) / mid;
            }
            if(h_n <= h){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1 ;
            }
        }
        return ans;
        
    }
};
