class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX); // initial distance 
        dist[src] = 0;// start 
        for (int i = 0; i <= k ; i++){ // most k steps 
            vector<int> temp = dist;

            for (const auto& flight : flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];

                if (dist[u] != INT_MAX){
                    temp[v] = min(temp[v], dist[u] + w);
                }
            }
            dist = temp;
        }
            return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
