class Solution {
public:
    //make Dp array 
    string dp[5001];
    string solve(auto &cost , int target){
        if(target == 0){
            return "" ; //return an empty string 
        }

        if(dp[target] != "#") return dp[target];

        string ans = "";

        for(int d = 1 ; d <= 9 ; d ++){
            if(target >= cost[d - 1]){
                string temp = solve(cost , target - cost[d - 1]);

                if(target - cost[d - 1] == 0 || temp != ""){
                    temp = char('0' + d) + temp;
                }

                //maximuizing the ans
                if(ans == "" || temp.size() > ans.size() || (temp.size() == ans.size() && temp > ans)){
                    ans = temp;
                }
            }
        }

        return dp[target] = ans;
    }
    string largestNumber(vector<int>& cost, int target) {
        for(int i = 0 ; i < 5001 ; i ++){
            dp[i] = "#";
        }

        //Now do the recursion
        string ans = solve(cost , target);

        if(ans == "") {
            return "0";
        }
        
        return ans;
    }
};