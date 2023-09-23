class Solution {
public:
    int maxProfit(vector<int>& prices) {
    vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
    //   return  helper(prices,0,1,dp);
    for(int index=prices.size()-1;index>=0;index--){
        for(int buy=0;buy<=1;buy++){
                  if(buy==1){//can buy
            int buyy=-prices[index]+dp[index+1][0];//bought
            int keep=dp[index+1][1];//keep dont buy new
             dp[index][buy]=max(buyy,keep);//return jo max de
        }
        else{
        int sell=prices[index]+dp[index+2][1];//sold

        int keep=dp[index+1][0];//keep
             dp[index][buy]=max(sell,keep);
        }
        //buy nhi krskte ab sell krskte hain ya purana hi rkh skte
        }
    }
    return dp[0][1];
    }
};