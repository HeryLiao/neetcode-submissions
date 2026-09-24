class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool has_x = false;
        bool has_y = false;
        bool has_z = false;
        
        int x = target[0];
        int y = target[1];
        int z = target[2];
        for (const auto& t : triplets){
            if (t[0] <= x && t[1] <= y && t[2] <=z){
                if (t[0] == x) has_x = true;
                if (t[1] == y) has_y = true;
                if (t[2] == z) has_z = true;
            }
        }
        return has_x && has_y && has_z;
    }
};
