class Solution {
    bool isPossible(vector<int>& weights,int mid, int days,int n){
        int day=0;
        int sum=0;
        
        for(int i=0;i<n;i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                sum=0;
                sum+=weights[i];
                day++;
               
            }
            
             if(day>days){
                return false;
            }
        
        }
        if(sum<=mid){
            day++;
        }
        if(day>days){
                return false;
            }
        
        return true;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int high=0;
        int low=0;
        for(int i=0;i<n;i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
        
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(weights,mid,days,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    
};