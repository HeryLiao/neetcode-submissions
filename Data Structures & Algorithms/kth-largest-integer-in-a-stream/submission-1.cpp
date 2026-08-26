class KthLargest {
private:
    priority_queue<int , vector<int> , greater<int>> q;
    int kth;
public:
    KthLargest(int k, vector<int>& nums) {
        kth = k ;
        for(int i = 0 ; i <nums.size() ; i++){
            add(nums[i]);
        }
    }

    int add(int val) {
       q.push(val);
       if(q.size() > kth){
            q.pop();
       }
       return q.top();
    }
};
