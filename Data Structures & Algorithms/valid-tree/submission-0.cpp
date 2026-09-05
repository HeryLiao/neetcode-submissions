class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& count){
        visited[node] = true;
        count++;
        for (int neighbor : adj[node]){
            if (!visited[neighbor]){
                dfs(neighbor, adj, visited, count);
            }
        }
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
            //tree no cycle edge = n - 1
            if (edges.size() != n - 1) return false;
            vector<bool> visited (n, false);
            vector<vector<int>> adj(n);
            for (auto& edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
            int count = 0;
            dfs(0, adj, visited, count);

            return count == n;
    }
};
