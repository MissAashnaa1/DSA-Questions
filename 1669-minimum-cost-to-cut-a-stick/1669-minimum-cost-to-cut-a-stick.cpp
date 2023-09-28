class Solution {
    int helper(int start,int end, vector<int>& cuts,int left,int right,vector<vector<int>>&dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int Cost=1e8;
        for(int i=left;i<=right;i++){
            int prevcut=helper(start,cuts[i],cuts,left,i-1,dp);

            int nextcut=helper(cuts[i],end,cuts,i+1,right,dp);
            int tempCost=nextcut+prevcut+end-start;
            Cost=min(Cost,tempCost);
        }
        return dp[left][right]=Cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(0,n,cuts,0,cuts.size()-1,dp);
    }
};