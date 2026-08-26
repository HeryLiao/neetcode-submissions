class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,vector<int>>> hp;
       for(const auto&p : points){
            int dist = p[0] * p[0] + p[1] * p[1];
            hp.push({dist,p});

            if(hp.size() > k){
                hp.pop();
            }
       } 
       vector<vector<int>>res; //2-d array for return ans
       while(!hp.empty()){
            res.push_back(hp.top().second); // second is coordinate
            hp.pop();
       }
       return res;
    }
};
