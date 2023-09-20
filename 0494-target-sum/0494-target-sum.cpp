class Solution {
public:
    int helper(vector<int>& nums,int target, int i,int ans){
          if(i>=nums.size()){
             if(ans==target)
                return 1;
            return 0;
         }
         
           return   helper(nums,target,i+1,ans+nums[i])  + helper(nums,target,i+1,ans-nums[i]);
         
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      
        return helper(nums,target,0 ,0);
        
    }
};