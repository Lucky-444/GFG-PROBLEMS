class Solution {
  public:
    int prefixStrings(int N) {
        // code here
        vector<int> v(N+1,0);
        v[0]=1;
        v[1]=1;
        int m= 1e9+7;
        for (int i = 2; i <=N; ++i)
        {
            for(int j=0;j<i; j++){
                v[i] = (v[i]+ (1LL *v[j]* v[i-1-j])%m)%m;
            }
        }

        return v[N];
    }
};