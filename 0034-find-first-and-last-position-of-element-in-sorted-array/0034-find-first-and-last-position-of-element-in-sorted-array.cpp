class Solution {
    int firstOcc(vector<int>& nums, int target,int &n){
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                ans= mid;
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
    int lastOcc(vector<int>& nums, int target,int &n){
        int left=0;
        int right=n-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                ans= mid;
                left=mid+1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=firstOcc(nums,target,n);
        int last=lastOcc(nums,target,n);
    return {first,last};
    }
};