class Solution {
  public:
    stack<char>done , undone; 
    void append(char x) {
        // append x into document
        done.push(x);
        
        
        //after one push all redo function are invalid
        while(!undone.empty()){
            undone.pop();
        }
    }

    void undo() {
        // undo last change
        if(!done.empty()){
            undone.push(done.top());
            done.pop();
        }
    }

    void redo() {
        // redo changes
        if (!undone.empty()) {
            done.push(undone.top());
            undone.pop();
        }
    }

    string read() {
        // read the document
        
        string ans = "";
        stack<char> temp = done;

        // stack gives reverse order, so collect first
        while (!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};