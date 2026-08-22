class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = n*m - 1;
        while(left <= right){
           int mid = left + (right - left) /2;
           int r = mid / n;
           int c = mid % n;
           if(matrix[r][c] > target ){
             right = mid - 1;
           }
           else if (matrix[r][c] < target){
            left = mid + 1 ;
           }
           else if (matrix[r][c] == target){
            return true;
           }

        }
        return false;
    }
};
