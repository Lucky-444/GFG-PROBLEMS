// User function Template for C++

class Solution {
  public:
    void heapify(int n , auto &arr , int idx){
        int largest = idx ;
        
        int left = 2 * idx + 1;
        int right= 2 * idx + 2;
        
        if(left < n && arr[left] > arr[largest]){
            largest = left; 
        } 
        
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        
        if(largest != idx){
            swap(arr[largest] , arr[idx]);
            heapify(n , arr , largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // code here
        //start from Non Leaf Node
        for(int i = N/2-1; i >= 0; i--){
            heapify(N, arr, i);
        }        
    }
};
