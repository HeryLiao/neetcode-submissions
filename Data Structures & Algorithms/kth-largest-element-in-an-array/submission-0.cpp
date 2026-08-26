class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int>> mh;
        for(const auto& n : nums){
            mh.push(n);
            if(mh.size() > k){
                mh.pop();
            }
        }
        return mh.top();    
    }
};
