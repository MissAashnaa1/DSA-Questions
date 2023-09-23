class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
        int sell=prices[index]+dp[1]-fee;//sold

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