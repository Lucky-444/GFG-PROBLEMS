class Solution {
public:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;

            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    int minConnect(int V, vector<vector<int>>& edges) {
        // If total edges < V-1 → impossible
        if (edges.size() < V - 1) return -1;

        DSU dsu(V);

        for (auto &e : edges) {
            dsu.unite(e[0], e[1]);
        }

        // Count connected components
        int components = 0;
        for (int i = 0; i < V; i++) {
            if (dsu.find(i) == i) components++;
        }

        // We need components - 1 operations
        return components - 1;
    }
};
