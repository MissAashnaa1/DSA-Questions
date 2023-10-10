class Solution {
    bool isPossible(vector<int>&bloomDay,int mid,int m,int k,int n){
        int count=0;
        int adj=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                adj++;
            }
            else{
                adj=0;
            }
            if(adj==k){
                count++;
                adj=0;
            }
            if(count==m){
                return true;
            }

        }
        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();

        long long int val=m;
        if(n<val*k){
            return -1;
        }
        int low=INT_MAX;
        int high=0;
        for(int i=0;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(bloomDay,mid,m,k,n)){
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