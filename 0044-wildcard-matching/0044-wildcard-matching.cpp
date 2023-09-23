class Solution {
    bool helper(string &s, string &p,int n,int m,vector<vector<int>>&dp){
        if(n<0&&m<0){
            return 1;
        }
        if(m<0&&n>=0){
            return 0;
        }
        if(n<0&&m>=0){
            while(m>=0){
                if(p[m]=='*'){
                    --m;
                }
                else{
                    return 0;
                }
                
                
            }
            return 1;
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s[n]==p[m]||p[m]=='?'){
            return dp[n][m]=helper(s,p,n-1,m-1,dp);
        }
        if(p[m]=='*'){
            return dp[n][m]=helper(s,p,n,m-1,dp)||helper(s,p,n-1,m,dp);
        }
        return dp[n][m]=0;
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length(),vector<int>(p.length(),-1));
        return helper(s,p,s.size()-1,p.size()-1,dp);
    }
};