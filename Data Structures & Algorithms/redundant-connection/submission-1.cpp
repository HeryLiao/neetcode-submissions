class UnionFind{
private:
    vector<int> parent;
public:
    UnionFind(int n){
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if (parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool unite(int i,int j){
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j){
            return false;
        }
        parent[root_i] = root_j;
        return true;
    }


};

class Solution {

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);

        for (auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            if (!uf.unite(u, v)){
                return edge;
            }
        }
        return {};
    }
};
