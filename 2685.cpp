2685. Count the Number of Complete Components


static struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N + 1, -1); }

    // get representive component (uses path compression)
    int leader(int x) { return e[x] < 0 ? x : e[x] = leader(e[x]); }

    bool same_set(int a, int b) { return leader(a) == leader(b); }

    int size(int x) { return -e[leader(x)]; }

    bool unite(int x, int y) {  // union by size
        x = leader(x), y = leader(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        DSU dsu(n + 5);
        vector<int> indegree(n + 5);
        for(auto el : edges) dsu.unite(el[0], el[1]), indegree[el[0]]++, indegree[el[1]]++;
        vector<int> comp[n];
        for(int i = 0; i < n; i++) comp[dsu.leader(i)].push_back(i);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int sz = comp[i].size(), sum = 0;
            if(sz == 0) continue;
            for(auto j : comp[i])  sum += indegree[j];
            if(sum == (sz * (sz - 1))) cnt++;
        }
        return cnt;
    }
};
