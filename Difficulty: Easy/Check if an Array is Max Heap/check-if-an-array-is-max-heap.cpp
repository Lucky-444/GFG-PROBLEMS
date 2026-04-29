class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
         // Your code goes here
        //first check is array to heap reprsentts as CBT 
        //if CBT then check maximum Property 
        /*
            An array represents a Max Heap if:

            It already represents a Complete Binary Tree
            👉 Any array representation automatically satisfies CBT, so no check needed
            
            It satisfies the Max Heap property
            👉 Every parent ≥ its children
        
        */
        
        int n = arr.size();
        
        //Only need to check non-leaf Nodes 
        for(int i = 0 ; i < n / 2  ; i ++){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            
            // If left child exists and is greater than parent
            if (left < n && arr[i] < arr[left]) {
                return false;
            }
            
            // If right child exists and is greater than parent
            if (right < n && arr[i] < arr[right]) {
                return false;
            }
        }
        
          
        // If all parent nodes satisfy max heap property
        return true;
    
    }
};
