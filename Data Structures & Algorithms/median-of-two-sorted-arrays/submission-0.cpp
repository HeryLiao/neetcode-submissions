class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2 , nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int l = 0 ;//left
        int r = m ;// smaller array
        int h_l = ( m + n + 1 ) / 2; // force carry
        while(l <= r){
            int i = l + (r - l) /2 ; // nums1 cut point
            int j = h_l - i ; // nums2 cut point

            int max_l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int min_r1 = (i == m) ? INT_MAX : nums1[i];

            int max_l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int min_r2 = (j == n) ? INT_MAX : nums2[j];
            if (max_l1 > min_r2){
                r = i - 1;
            }
            else if (max_l2 > min_r1){
                l = i + 1;
            }
            else {
                if((m + n) % 2 == 1){
                    return max(max_l1 , max_l2);
                }
                else{
                    return (max(max_l1,max_l2) + min(min_r1,min_r2)) / 2.0 ;
                }
            }
        }
        
        return 0.0;
    }
};
