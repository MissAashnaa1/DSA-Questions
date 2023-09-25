class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
    int n=arr.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);

    vector<int>v;

    int last=0;
    int maxi=1;
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                if(dp[i]==1+dp[prev_index]){
                    cnt[i]=cnt[prev_index]+cnt[i];
                }
                if(dp[i]<1+dp[prev_index]){
                    dp[i]=1+dp[prev_index];
                    cnt[i]=cnt[prev_index];
                    
                }
                
            }
           
            maxi=max(maxi,dp[i]);
        }
        
        
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            
            ans+=cnt[i];
        }
    }
    return ans;
    }
};