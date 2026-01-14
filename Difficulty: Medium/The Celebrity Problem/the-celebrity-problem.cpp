class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        map<int,int> indegree;
        map<int,int> outdegree; 
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && mat[i][j]){ // ignore self
                    indegree[j]++;
                    outdegree[i]++;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0 && indegree[i] == n - 1){
                return i;
            }
        }
        
        return -1;
    }
};
