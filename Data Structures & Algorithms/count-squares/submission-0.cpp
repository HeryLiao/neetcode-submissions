class CountSquares {
private:
    int cnt[1001][1001] = {0};
    // 0 <= x, y <= 1000
    vector<pair<int, int>> pts;
public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        pts.push_back({x,y});
        cnt[x][y]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int res = 0;
        for (auto& p : pts){
            int x = p.first;
            int y = p.second;
            if (x == px || abs(x - px) != abs(y - py)){
                continue;
            }
            res += cnt[x][py] * cnt[px][y];
        }
        return res;
    }
};
