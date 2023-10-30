class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(i<n){
            int correct=nums[i];
            if(nums[i]==n){
                i++;
                continue;
            }
            if(nums[correct]==nums[i]){
                i++;
            }
            else{
                swap(nums[correct],nums[i]);
            }
        }
        for( i=0;i<n;i++)
        {
            if(nums[i]!=i){
                return i;
            }
        }
        return n;
    }
};