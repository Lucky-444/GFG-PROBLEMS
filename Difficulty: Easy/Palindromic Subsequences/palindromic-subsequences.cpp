int MinRemove(int n, string s) {
    // complete the function here
    string rev = s;
    reverse(rev.begin() ,rev.end());
    
    if(s == rev){
        return 1;
    } 
    
    int cnt_one = 0 , cnt_zero = 0;
    for(auto it : s){
        if(it == 1){
            cnt_one++;
        }else{
            cnt_zero++;
        }
    }
    
    return 2;
}