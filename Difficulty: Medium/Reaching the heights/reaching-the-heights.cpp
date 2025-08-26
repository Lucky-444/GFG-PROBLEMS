// User function Template for C++

vector<int> reaching_height(int n, int a[]) {
    // Complete the function
    
    vector<int>sorted;
    for(int i = 0; i < n ; i++){
        sorted.push_back(a[i]);
    }
    
    sort(sorted.rbegin(), sorted.rend());
    
    vector<int>ans(n);
    int l = 0, r = n-1;
    for(int i = 0 ; i < n ; i++){
        bool odd = ((i + 1) & 1);
        
        if(odd){
            ans[i] = sorted[l++];
        }else{
            ans[i] = sorted[r--];
        }
    }
    
    // Now check if elevator ever touches ground
    long long floor = 0, highest = 0;
    for(int i = 0; i < n; i++) {
        if((i+1) & 1) floor += ans[i]; // odd → up
        else floor -= ans[i];          // even → down

        if(floor <= 0) return {-1}; // invalid
        highest = max(highest, floor);
    }

    
    return ans;
}
