class Solution {
public:
    int helper(int sum, int cursum, int index, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(index==nums.size()){
            if(cursum==target) return 1;
            else return 0;
        }
        //adjustment with offset to cover up -ve sum as index cant be negative
        if(dp[index][cursum+sum]!=-1) return dp[index][cursum+sum];

        //no. of ways if we chose +nums[index]
        int take1 = helper(sum,cursum+nums[index],index+1,nums,target,dp);
        //no. of ways if we chose -nums[index]
        int take2 = helper(sum,cursum-nums[index],index+1,nums,target,dp);

        //store and return total number of ways
        return dp[index][cursum+sum]=take1+take2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
     int n = nums.size();
        //Finding the range of maximum sum and minimum sum that can be formed with nums
        int sum = accumulate(nums.begin(), nums.end(), 0);

        //dp table with all the possible combinationof index and sum
        vector<vector<int>> dp(n, vector<int> (2*sum+1, -1));
        
        //edge cases
        if(target>sum||target<-sum){
            return 0;
        }
        return helper(sum,0,0,nums,target,dp);
    }
};