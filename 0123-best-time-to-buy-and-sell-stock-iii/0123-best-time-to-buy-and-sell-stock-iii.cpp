class Solution {

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,             vector<vector<int>>(2,
        vector<int>(4,0)));
        for(int index=prices.size()-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap>=0;cap--){
    if(buy==1){//cap<2
            int buyy=-prices[index]+dp[index+1][0][cap];
            //3
            int keep=dp[index+1][1][cap];// 1
            dp[index][buy][cap]= max(buyy,keep);
        }
        //buy==0
        else{

            int sell=prices[index]+dp[index+1][1][cap+1];
            int keep=dp[index+1][0][cap];// 2
             dp[index][buy][cap]= max(sell,keep);                
        }
                }
            }

        }
    return dp[0][1][0];
    }
};