class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int max_area = 0;
        stack<int> st;
        for(int i = 0 ; i <= n ; i++){
            int cur_h = (i==n) ? 0 : heights[i];
            while(!st.empty() && cur_h < heights[st.top()]){
                int temp = st.top();
                st.pop();
                int h = heights[temp];
                int w = st.empty() ? i : ( i - st.top() -1 );
                max_area = max(max_area , h * w);
            }
            st.push(i);
        }

        
        return max_area;
    }
};
