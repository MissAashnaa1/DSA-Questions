class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
               int i=0;
        int n=nums.size();
        vector<int>v;
        while(i<n){
            int correct=nums[i]-1;
            if(nums[i]>n){
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
        for( i=1;i<=n;i++)
        {
            if(nums[i-1]!=i){
                v.push_back(i);
            }
        }
        return v;
    }
};