// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void Heapify(vector<int>&arr , int n , int idx){
        int largest = idx ; 
        
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        
        if(left < n && arr[left] > arr[largest]){
            largest = left ; 
        }
        
        if(right < n && arr[right] > arr[largest]){
            largest = right; 
        }
        
        if(largest != idx){
            swap(arr[idx] , arr[largest]);
            Heapify(arr , n , largest); //Recurse for next down child
            
        }
    }
    void heapSort(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        //start from Leaf node and make maxHeap 
        for(int i = (n / 2) ; i >= 0 ; i --){
            Heapify(arr, n , i);
        }
        
        //now swap the last with first element and remove the top 
        //and get the maximum at last
        
        for(int i = n - 1 ; i >= 0 ; i --){
            swap(arr[i] , arr[0]);
            
            Heapify(arr , i , 0);
        }
        
    }
};