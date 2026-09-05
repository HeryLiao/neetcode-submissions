class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});

        int total_cost = 0;
        int edges_count = 0;
        while (!pq.empty() && edges_count < n){
            auto [cost, u] = pq.top();
            pq.pop();
            if (visited[u] == true) continue;
            visited[u] = true;
            total_cost += cost;
            edges_count++;

            for (int i = 0; i < n; i++){
                if (!visited[i]){
                    int dist = abs(points[u][0] - points[i][0]) + abs (points[u][1] - points[i][1]);
                    pq.push({dist, i});
                }
            } 
        }
        return total_cost;
    }
};
