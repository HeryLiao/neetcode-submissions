class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order.push_back(curr);

            for (int next_course : adj[curr]) {
                indegree[next_course]--;
                if (indegree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        } 

        if (order.size() == numCourses) {
            return order;
        }
        return {};
    }
    
};
