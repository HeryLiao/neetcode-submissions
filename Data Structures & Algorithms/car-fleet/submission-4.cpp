class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //stack<double> st;
        int d = target;
        int n = position.size();
        int result = n;
        vector<pair<int , double>> cars(n);
        for(int i = 0 ; i < n ; i++){
            double time = (double)(d - position[i]) / speed[i];
            cars[i] = {position[i] , time};
        }
        sort(cars.begin(),cars.end(),greater<pair<int , double>>());
        double max_time = 0.0;
        for(int i = 0 ; i < n ; i++){
           if(cars[i].second <= max_time){
                result--;
           }
           else{
                max_time = cars[i].second;
           }

        }
        return result;
    }
};
