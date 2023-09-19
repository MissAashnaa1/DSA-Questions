class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,1e5);
        
        
        
        for(int i=0;i<coins.size();i++){
            dp[0]=0;
            for(int target=1;target<=amount;target++ ){
                // consider taking or not taking 
                int notTake=dp[target];
                int take=1e5;
                if(target>=coins[i])
                    take=1+dp[target-coins[i]];
                dp[target]=min(notTake,take);

            }
        }
        if(dp[amount]==1e5){return -1;}
        return dp[amount];
    }

};