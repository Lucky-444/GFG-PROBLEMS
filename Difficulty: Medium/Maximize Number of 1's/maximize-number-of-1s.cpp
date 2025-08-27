class Solution {
  public:
  /*
  [1,0,0,1,0,1,0,1]
     ↑
     i,j
    
    [1,0,0,1,0,1,0,1]
     ↑-----↑
     i     j   (window length 4)
    
    [1,0,0,1,0,1,0,1]
         ↑-------↑
         i       j   (window length 5, final max)
         
    Perfect 👌 this is the **classic sliding window problem**:
                
                👉 "Find the longest subarray containing at most `k` zeros" (here `k=2`).
                Your code is correct. Let’s **dry run** on
                
                ```
                arr = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
                ```
                
                ---
                
                ### Variables:
                
                * `i` = left pointer
                * `j` = right pointer
                * `zero_cnt` = number of zeros in current window
                * `ans` = max length so far
                
                ---
                
                ### Step-by-step with diagram
                
                #### Start:
                
                ```
                i = 0, j = 0, zero_cnt = 0, ans = -1
                ```
                
                ---
                
                #### j = 0 → arr\[0] = 1
                
                ```
                zero_cnt = 0
                window = [1]
                ans = max(-1, 1) = 1
                ```
                
                ---
                
                #### j = 1 → arr\[1] = 0
                
                ```
                zero_cnt = 1 (<= k)
                window = [1, 0]
                ans = max(1, 2) = 2
                ```
                
                ---
                
                #### j = 2 → arr\[2] = 0
                
                ```
                zero_cnt = 2 (<= k)
                window = [1, 0, 0]
                ans = max(2, 3) = 3
                ```
                
                ---
                
                #### j = 3 → arr\[3] = 1
                
                ```
                zero_cnt = 2
                window = [1, 0, 0, 1]
                ans = max(3, 4) = 4
                ```
                
                ---
                
                #### j = 4 → arr\[4] = 0
                
                ```
                zero_cnt = 3 (> k) ❌
                Shrink window:
                  arr[i=0] = 1 → not zero → i=1
                  arr[i=1] = 0 → zero_cnt=2, i=2
                Now zero_cnt = 2 ✅
                window = [0, 1, 0] (i=2..4)
                ans = max(4, 3) = 4
                ```
                
                ---
                
                #### j = 5 → arr\[5] = 1
                
                ```
                zero_cnt = 2
                window = [0, 1, 0, 1] (i=2..5)
                ans = max(4, 4) = 4
                ```
                
                ---
                
                #### j = 6 → arr\[6] = 0
                
                ```
                zero_cnt = 3 (> k) ❌
                Shrink window:
                  arr[i=2] = 0 → zero_cnt=2, i=3
                Now zero_cnt=2 ✅
                window = [1, 0, 1, 0] (i=3..6)
                ans = max(4, 4) = 4
                ```
                
                ---
                
                #### j = 7 → arr\[7] = 1
                
                ```
                zero_cnt = 2
                window = [1, 0, 1, 0, 1] (i=3..7)
                ans = max(4, 5) = 5 ✅
                ```
                
                ---
                
                ### Final Answer:
                
                ```
                ans = 5
                ```
                
                ---
                
                ### Diagram (Window movement)
                
                ```
                [1,0,0,1,0,1,0,1]
                 ↑
                 i,j
                
                [1,0,0,1,0,1,0,1]
                 ↑-----↑
                 i     j   (window length 4)
                
                [1,0,0,1,0,1,0,1]
                     ↑-------↑
                     i       j   (window length 5, final max)
                ```
                
                ✅ Maximum consecutive `1`s (with at most 2 zero flips) = **5**
                
                ---
                
                Do you want me to also **show the subarray itself** (which positions make this length 5)?


  */
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int i = 0 , j = 0 , ans = -1;
        int zero_cnt = 0;
        
        while(j < n){
            if(arr[j] == 0){
                zero_cnt ++;
            }
            
            while(zero_cnt > k){
                if(arr[i] == 0){
                    zero_cnt --;
                }
                
                i++;
            }
            
            ans = max(ans , j - i + 1);
            j++;
        }
        
        return ans;
    }
};
