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
    int secondMST(int n, vector<vector<int>> &edges) {
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
        
       ll second = LLONG_MAX;

        for(auto it : st){

            int u = it.first;
            int v = it.second;

            DSU ds2(n);
            ll cost = 0;
            int edgesUsed = 0;

            for(auto it2 : vec){

                int wt = it2.first;
                int u1 = it2.second.first;
                int v1 = it2.second.second;

                if((u1 == u && v1 == v) || (u1 == v && v1 == u)){
                    continue;
                }

                if(ds2.Find(u1) != ds2.Find(v1)){
                    ds2.Union(u1 , v1);
                    cost += wt;
                    edgesUsed++;
                }
            }

            if(edgesUsed == n-1 && cost > ans){
                second = min(second , cost);
            }
        }

        return second == LLONG_MAX ? -1 : second;
    }
};