class Solution {
    int helper(vector<int>& prices,int index,int buy,int cap,
    vector<vector<vector<int>>>&dp){
        if(index==prices.size()||cap==2)
            return 0;
        if(dp[index][buy][cap]!=-1)
            return dp[index][buy][cap];
        if(buy==1){//cap<2
            int buyy=-prices[index]+helper(prices,index+1,0,cap,dp);
            //3
            int keep=helper(prices,index+1,1,cap,dp);// 1
            return  dp[index][buy][cap]= max(buyy,keep);
        }
        //buy==0
            int sell=prices[index]+helper(prices,index+1,1,cap+1,dp);
            int keep=helper(prices,index+1,0,cap,dp);// 2
            return dp[index][buy][cap]= max(sell,keep);
        
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size() ,                vector<vector<int>>(2,
        vector<int>(3,-1)));
        //prices,index 0->n, buy =0,1,cap=0,1,2
        return helper(prices,0,1,0,dp);
    }
};