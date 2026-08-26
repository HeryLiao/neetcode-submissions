class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int , vector<int> , less<int>>q;//maxheap
        for(auto a : stones){
            q.push(a);
        }
        while(q.size() >= 2){
            int temp1 = q.top();
            q.pop();
            int temp2 = q.top();
            q.pop();
            if(temp1 != temp2){
                temp1 -= temp2;
                q.push(temp1);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
