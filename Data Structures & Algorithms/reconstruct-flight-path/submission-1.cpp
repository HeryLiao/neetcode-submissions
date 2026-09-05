class Solution {
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(const string& airport){
        while (!adj[airport].empty()){ 
            string next_port = adj[airport].top();
            adj[airport].pop();
            dfs(next_port);
        }
        result.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets){
            adj[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
        
    }
};
