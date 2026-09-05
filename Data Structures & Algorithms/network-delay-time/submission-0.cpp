class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }

        const int INF = 1e9;
        vector<int> dist(n + 1, INF); // initial forall vertex dist are INF
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()){
            auto[d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto& edge : adj[u]){
                int v = edge.first;
                int weight = edge.second;
                if(dist[u] + weight < dist[v]){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        int max_time = 0;
        for (int i = 1; i <= n; i++){
            if (dist[i] == INF) return -1;
            max_time = max(max_time, dist[i]);
        }
        return max_time;
    }
};
