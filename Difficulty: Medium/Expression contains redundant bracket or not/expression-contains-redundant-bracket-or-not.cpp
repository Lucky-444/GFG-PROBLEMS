class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        
        /*
        Why?
        (a) → redundant ❌
        ((a+b)) → outer () redundant ❌
        (a+(b)/c) → (b) redundant ❌
        (a+b+(c+d)) → (c+d) has operator + → not redundant
        */
        
        /*
        Use a stack of characters
        
        Traverse the string:
        
        Push every character except )
        
        When you encounter ):
        
        Pop characters until ( is found
        
        Check if an operator (+ - * /) exists
        
        If no operator found → redundant parentheses found → return true
        
        If traversal ends without finding redundancy → return false
        */
        
        stack<char>st;
        
        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i] != ')'){
                st.push(s[i]);
            }
            
            else {
                bool hasOp = false; 
                
                while(!st.empty() && st.top() != '('){
                    char topChar = st.top();
                    st.pop();

                    if (topChar == '+' || topChar == '-' ||
                        topChar == '*' || topChar == '/') {
                        hasOp = true;
                    }
                }
                
                // Remove '('
                st.pop();

                // If no operator found → redundant
                if (!hasOp) return true;
            }
        }
        
        return false ;
    }
};
