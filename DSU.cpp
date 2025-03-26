

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



