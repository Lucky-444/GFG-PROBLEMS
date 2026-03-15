class DSU{
    public : 
    vector<int>parent , rank;
    int components;
    
    DSU(int n){
        parent.resize(n , 0);
        rank.resize(n , 1);
        
        iota(parent.begin() , parent.end() , 0);
        components = n;
    }
    
    int Find(int u){
        return u == parent[u] ? u : parent[u] = Find(parent[u]);
    }
    
    void Union(int u , int v){
        u = Find(u);
        v = Find(v);
        
        if(u == v){
            return ;
        }
        
        if(rank[u] < rank[v]){
            parent[u] = v;
        }else if(rank[u] > rank[v]){
            parent[v] = u;
        }else{
            parent[v] = u;
            rank[u] ++;
        }
        
        components --;
    }
    
};

class Solution {
  public:
    using ll = long long;
    using P = pair<int , pair<int , int>>;
    int spanningTree(int n, vector<vector<int>>& edges) {
        // code here
        vector<P>vec;
        
        for(auto it : edges){
            vec.push_back({it[2] , {it[0] , it[1]}});
        }
        
        sort(vec.begin() , vec.end());
        
        ll ans = 0;
        DSU ds(n);
        ll cnt = 0;
        set<pair<int , int>>st;
        
        for(auto it : vec){
            ll u = it.second.first;
            ll v = it.second.second;
            ll wt = it.first;
            
            if(ds.Find(u) != ds.Find(v)){
                ds.Union(u , v);
                ans += wt;
                cnt ++;
                st.insert({u , v});
            }
            
        }
        
        if(cnt != n - 1){
            return -1;
        }
        
        return ans;
    }
};