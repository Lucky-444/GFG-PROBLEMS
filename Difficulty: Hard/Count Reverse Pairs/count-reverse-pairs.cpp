class Solution {
  public:
    int cnt = 0;
    int n ;
       void count_valid_pairs(vector<int> &arr,int l,int mid ,int h){
        int j=mid+1;
        long long two=2;
        for(int i=l; i<=mid; i++){
            while(j<=h&&arr[i]>arr[j]*two){
                j++;
            } 
            cnt=cnt+(j-(mid+1));
        }
    }
  
    void merge(vector<int> &arr,int l,int mid ,int h){
        int left=l;
        int right=mid+1;
        vector<int>temp;
        while(left<=mid&&right<=h){
            if(arr[left]<=arr[right])
                temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        
         while(right<=h){
            temp.push_back(arr[right++]);
        }      
        
        for(int i=l; i<=h; i++){
            arr[i]=temp[i-l];
        }
    }
    void  merge_sort(vector<int> &arr,int l, int h){
        if(l>=h) return;
        long long mid=l+(h-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        count_valid_pairs(arr,l,mid,h);
        merge(arr,l,mid,h);
    }
    int countRevPairs(vector<int> &arr) {
        // Code here
        n = arr.size();
         merge_sort(arr,0,n-1);
         return cnt;
    }
};