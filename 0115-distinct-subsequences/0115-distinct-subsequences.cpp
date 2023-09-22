class Solution {
    int helper(string s,string t, vector<vector<int>>&dp,int ind1,int ind2 ){
        if(ind2<0){
            return 1;
        }
        if(ind1<0){
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s[ind1]==t[ind2])
        return dp[ind1][ind2]=helper(s,t,dp,ind1-1,ind2-1)+helper(s,t,dp,ind1-1,ind2);
        else return dp[ind1][ind2]=helper(s,t,dp,ind1-1,ind2);
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));

        return helper(s,t,dp,s.length()-1,t.length()-1);

    }
};