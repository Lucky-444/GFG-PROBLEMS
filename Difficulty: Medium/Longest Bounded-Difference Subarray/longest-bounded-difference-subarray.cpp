class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int i = 0;int j = 0;
        int l = 1;
        vector<int> ans;
        int n = arr.size();
        map<int,int> mp;
        int index1 = 0;
        int index2 = 0;
        while(i<n && j < n)
        {
            mp[arr[j]]++;
            int maxi = mp.rbegin()->first;
            int mini = mp.begin()->first;
            if(abs(maxi - mini) <= x){ 
                
                if(j-i+1 >l){
                    index1 = i;
                    index2 = j;
                     l = j-i+1;  
                   }
                    
            }
            else 
            {
                while(abs(maxi - mini)>x)
                {
                    mp[arr[i]]--;
                    if(mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                    
                    i++;
                    maxi = mp.rbegin()->first;
                    mini = mp.begin()->first;
                }
            }
            j++;
            
        }
        
        for(int k = index1;k<=min(index2,n-1);k++)
        {
            ans.push_back(arr[k]);
        }
        return ans;
        
    }
};