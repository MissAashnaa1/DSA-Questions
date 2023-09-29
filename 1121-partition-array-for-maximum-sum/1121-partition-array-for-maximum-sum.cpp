class Solution {
    int helper(int left,vector<int> &arr,int k,vector<int>&dp){
        int n=arr.size();
        if(left==n){
            return 0;
        }
        if(dp[left]!=-1)
            return dp[left];
        int maxEle=INT_MIN;
        int len=0;
        int tempCost=INT_MIN;
        for(int i=left;i<min(left+k,n);i++){
            len++;
            maxEle=max(maxEle,arr[i]);
             tempCost=max(tempCost,maxEle*len+helper(i+1,arr,k,dp));
            
        }
        return dp[left]=tempCost;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helper(0,arr,k,dp);
    }
};