class Solution {
    bool isPossible(vector<int>&piles,int mid,int h,int n){
        int hours=0;
        int ans=0;
        int did=0;
        int rem=0;
        for(int i=0;i<n;i++){
            hours+=piles[i]/mid;
            if(piles[i]%mid){
                hours++;
            }
            if(hours>h){
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int high=0;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        int low=1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(piles,mid,h,n)){
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