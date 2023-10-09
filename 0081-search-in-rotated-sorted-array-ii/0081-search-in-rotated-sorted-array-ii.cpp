class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        
        while(low<=high){
            int mid=(high+low) / 2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
             if(arr[mid]==target){
                return true;
            }
            if(arr[low]==arr[mid]&&arr[mid]==arr[high]){
                low++;
                high--;

            }
            
            else if(arr[low]<=arr[mid]){
                
                if(arr[low]<=target&&target<=arr[mid]){
                    
                    high=mid-1;
                    cout<<high<<endl;
                }
                else{
                    
                    low=mid+1;
                    cout<<low<<endl;
                }
            }
            else{
                if(arr[mid]<=target&&target<=arr[high]){
                    
                    low=mid+1;
                    // cout<<low<<endl;
                }
                else{
                    
                    high=mid-1;
                    //cout<<high<<endl;
                }
            }

        }
        return false;
    }
    
};