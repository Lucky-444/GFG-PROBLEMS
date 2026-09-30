class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int>ans;

        stack<char>st;

        for(auto ch : seq){
            if(ch == '('){
                st.push('(');
                ans.push_back(st.size() % 2);
            }
            else{
                ans.push_back(st.size() % 2);
                st.pop();
            }
        }

        return ans;
    }
};