class Solution {
     bool isPossible(vector<int>&arr,int n,int m,int mid){
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
            sum+=arr[i];
            }
            else{
                count++;
                sum=arr[i];
            }
        }
        if(sum<=mid){
            count++;
        }
        if(count<=m){
            return true;
        }
            return false;
        
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n){
            return -1;
        }
     int low = nums[0];
    
    int high=0;
    for(int i=0;i<n;i++){
        high+=nums[i];
        low=max(low,nums[i]);
        
    }
    // cout<<high<<" "<<low<<endl;
    
    int ans=    -1;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(nums,n,k,mid)){
            ans=mid;
            high=mid-1;
            
        }
        else{
            low=mid+1;
            
        }
    }
    return ans;
        //code 
    }
};