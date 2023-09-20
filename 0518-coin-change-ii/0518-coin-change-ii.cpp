class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[i]=1;
        }
        for(int i=1;i<coins.size();i++){
           dp[0]=1;
            for(int target=0;target<=amount;target++){
                int notTake=dp[target];
                int take=0;
                if(target>=coins[i])
                    take=dp[target-coins[i]];
                dp[target]=take+notTake;
            }
            
        }
        return dp[amount];
    }
};