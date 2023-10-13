class Solution {
    // int helper(vector<int>cost,vector<int>dp,int n){
    //     if(n==0){
    //         return dp[0]= cost[0];
    //     }
    //     if(n==1){
    //         return dp[1]= cost[1];
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }
    //     return dp[n]=cost[n]+min(helper(cost,dp,n-1),helper(cost,dp,n-2));
    // }
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
    //    int  n=cost.size();
    //      vector<int>dp(n+1,-1);
    //     return min(helper(cost, dp, n-1),helper(cost,dp,n-2));
    int prev2=cost[0];
    int prev=cost[1];
    int curr=0;
    for(int i=2;i<cost.size();i++){
        curr=cost[i]+min(prev,prev2);
        prev2=prev;
        prev=curr;
    }
    return min(prev,prev2);
    }
};