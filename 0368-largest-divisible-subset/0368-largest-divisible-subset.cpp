class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
       
        for(int i=1;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&dp[i]<(1+dp[prev])){
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
        }
        int last=0;
        for(int i=1;i<n;i++){
            if(dp[i]>dp[last])
                last=i;
        }
        vector<int>v;
        v.push_back(nums[last]);
        while(hash[last]!=last){
            v.push_back(nums[hash[last]]);
            last=hash[last];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};