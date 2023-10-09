class Solution {
public:
    int findMin(vector<int>& arr) {
         int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX;
        
        while(low<=high){
            int mid=(high+low) / 2;
            if(arr[low]<=arr[high]){
                
                ans=min(ans,arr[low]);
               break;
            }
             if(arr[low]<=arr[mid]){
                    ans=min(arr[low],ans);
                    low=mid+1;
             
            }
            else{
                 ans=min(arr[mid],ans);
                high=mid-1;
                   
            }

        }
        return ans;
    }
};