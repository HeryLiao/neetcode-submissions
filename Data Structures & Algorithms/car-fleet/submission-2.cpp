class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        int d = target;
        int n = position.size();
        int result = n;
        vector<pair<int , double>> cars(n);
        for(int i = 0 ; i < n ; i++){
            double time = (double)(d - position[i]) / speed[i];
            cars[i] = {position[i] , time};
        }
        sort(cars.begin(),cars.end(),greater<pair<int , double>>());

        for(int i = 0 ; i < n ; i++){
            double time1 = cars[i].second;
            if(st.empty() || time1 > st.top()){
                st.push(time1);
            }

        }
        return st.size();
    }
};
