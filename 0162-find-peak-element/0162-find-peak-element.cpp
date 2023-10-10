class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        if(high==0){
            return 0;
        }
        while(low<high){
            int mid=(high+low)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else high=mid;
        }
        return high;
    }
};