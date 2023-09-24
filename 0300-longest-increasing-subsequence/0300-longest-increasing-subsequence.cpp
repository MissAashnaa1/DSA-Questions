class Solution {
    int getAns(vector<int>& arr,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == arr.size())
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
    
    return getAns(nums,0,-1,dp);
    }
};