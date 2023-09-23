class Solution {
    // int helper(vector<int>& prices,int index,int buy, vector<vector<int>>&dp){
    //     if(index==prices.size())
    //         return 0;
    //     if(dp[index][buy]!=-1){
    //         return dp[index][buy];
    //     }
    //     if(buy==1){//can buy
    //         int buyy=-prices[index]+helper(prices,index+1,0,dp);//bought
    //         int keep=helper(prices,index+1,1,dp);//keep dont buy new
    //         return dp[index][buy]=max(buyy,keep);//return jo max de
    //     }
    //     //buy nhi krskte ab sell krskte hain ya purana hi rkh skte
    //     int sell=prices[index]+helper(prices,index+1,1,dp);//sold

    //     int keep=helper(prices,index+1,0,dp);//keep
    //     return dp[index][buy]=max(sell,keep);
    // }
public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
    //   return  helper(prices,0,1,dp);
    vector<int>dp(2,0);
    vector<int>ndp(2,0);
    for(int index=prices.size()-1;index>=0;index--){
        
        for(int buy=0;buy<=1;buy++){
                  if(buy==1){//can buy
            int buyy=-prices[index]+dp[0];//bought
            int keep=dp[1];//keep dont buy new
             ndp[buy]=max(buyy,keep);//return jo max de
        }
        else{
        int sell=prices[index]+dp[1];//sold

        int keep=dp[0];//keep
             ndp[buy]=max(sell,keep);
        }
        //buy nhi krskte ab sell krskte hain ya purana hi rkh skte
        }
        dp=ndp;
    }
    return dp[1];
    }
};