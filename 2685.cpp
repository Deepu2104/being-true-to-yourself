class Solution {
    
    struct DSU {
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n + 1);
            iota(parent.begin(), parent.end(), 0);
            size.resize(n + 1, 1);
        }

        int find_parent(int node){
            if(node == parent[node]) return node;
            return parent[node] = find_parent(parent[node]);
        }

        void merge(int u, int v){
            u = find_parent(u);
            v = find_parent(v);

            if(u != v){
                
                // bade graph me chota graph add hota h

                if(size[u] <= size[v]){
                    parent[u] = v;
                    size[v] += size[u];
                }else{
                    parent[v] = u;
                    size[u] += size[v];
                }
            }
        }

        int size_component(int node){
            return size[find_parent(node)];
        }

        int leader(int node){
            return find_parent(node);
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        DSU dsu(n);

        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            dsu.merge(u, v);
        }

        vector<int> count_edges(n);
        for(int i = 0; i < m; i++){
            int u = edges[i][0], v = edges[i][1];
            int leader = dsu.leader(u);
            count_edges[leader]++;
        }

        auto calc = [&](int x){
            return (x * (x - 1)) / 2;
        };

        int answer = 0;
        for(int i = 0; i < n; i++){
            if( i == dsu.leader(i) ){
                if(calc(dsu.size_component(i)) == count_edges[i]) answer++;
            }
        }
        return answer;
    }
};