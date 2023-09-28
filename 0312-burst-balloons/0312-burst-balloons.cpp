class Solution {
    int helper(int left,int right,vector<int>&nums,vector<vector<int>>&dp){
        if(left>right){
            return 0;
        }
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        int maxCost=INT_MIN;
        for(int i=left;i<=right;i++){
           
        
            maxCost=max(maxCost,nums[left-1]*nums[i]*nums[right+1]+helper(left,i-1,nums,dp)+helper(i+1,right,nums,dp));
        }
        return dp[left][right]=maxCost;
    }
public:
    int maxCoins(vector<int>& nums) {
      
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        // return helper(1,nums.size()-2,nums,dp);
        vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,0));
        for(int left=nums.size()-2;left>=1;left--){
            for(int right=1;right<=nums.size()-2;right++){
                if(left>right)
                    continue;
                    int maxCost=INT_MIN;
                    for(int i=left;i<=right;i++){
                        maxCost=max(maxCost,nums[left-1]*nums[i]*nums[right+1]+dp[left][i-1]+dp[i+1][right]);
                    }
                     dp[left][right]=maxCost;
                }
            }
        
        return dp[1][nums.size()-2];
    }
};