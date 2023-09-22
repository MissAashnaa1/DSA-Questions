class Solution {
    // int helper(string s,string t, vector<vector<int>>&dp,int ind1,int ind2 ){
    //     if(ind2<0){
    //         return 1;
    //     }
    //     if(ind1<0){
    //         return 0;
    //     }
        
    //     if(dp[ind1][ind2]!=-1){
    //         return dp[ind1][ind2];
    //     }
    //     if(s[ind1]==t[ind2])
    //     return dp[ind1][ind2]=helper(s,t,dp,ind1-1,ind2-1)+helper(s,t,dp,ind1-1,ind2);
    //     else return dp[ind1][ind2]=helper(s,t,dp,ind1-1,ind2);
    // }
public:
    int numDistinct(string s, string t) {
        // vector<vector<unsigned long long>>dp(s.size()+1,vector<unsigned long long>(t.size()+1,0));
    vector<unsigned long long>prev(t.size()+1);
    vector<unsigned long long>curr(t.size()+1);
    prev[0]=1;
        // return helper(s,t,dp,s.length()-1,t.length()-1);
        for(int i=1;i<=s.size();i++){
            curr[0]=1;
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1]+prev[j];// milgya yh manke aur nhi mila yh manke
                }
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return prev[t.size()];
    }
};