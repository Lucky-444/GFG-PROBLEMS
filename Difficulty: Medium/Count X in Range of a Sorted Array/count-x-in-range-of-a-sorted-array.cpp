class segTree{
    private: 
    vector<unordered_map<int ,int>>seg; 
    int n ;
    public :
    segTree(int n){
        seg.resize(4 * n);
        this -> n = n ;
    }
    
    void Build(int idx, int l ,int r ,vector<int>&nums){
        if (l == r) {
            seg[idx][nums[l]] ++;
            return;
        }

        int mid = (l + r) / 2;
        Build(2 * idx + 1, l, mid, nums);
        Build(2 * idx + 2, mid + 1, r, nums);

        // merge left and right
        for (auto &p : seg[2 * idx + 1])
            seg[idx][p.first] += p.second;

        for (auto &p : seg[2 * idx + 2])
            seg[idx][p.first] += p.second;
    }
    
    int query(int idx , int l , int r , int left , int  right , int val){
        if(r < left || l > right){
            return  0 ;
        }
        
        if(l >= left && r <= right){
            if(seg[idx].count(val)){
                return seg[idx][val]; 
            }
            
            return 0;
        }
        
        int mid = (l + r) >> 1; 
        return query(2 * idx + 1 , l , mid , left , right , val) + query(2 * idx + 2 ,mid + 1 , r , left , right , val);
    }
};


class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int, vector<int>> mp;

        // preprocess
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1], x = q[2];

            if (!mp.count(x)) {
                ans.push_back(0);
                continue;
            }

            auto &v = mp[x];
            int cnt = upper_bound(v.begin(), v.end(), r)
                    - lower_bound(v.begin(), v.end(), l);

            ans.push_back(cnt);
        }

        return ans;
    }
};