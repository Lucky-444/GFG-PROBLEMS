/*Complete the functions below*/
int find(int par[], int x) {
    // add code here
    if (x != par[x]) {
        par[x] = find(par, par[x]);
    }
    return par[x];
}

void unionSet(int par[], int x, int z) {
    // add code here.
    
     int u = find(par, x);
    int v = find(par, z);
    
    if (u == v) return;
    
    // Simple union
    par[u] = v;
    
    
}