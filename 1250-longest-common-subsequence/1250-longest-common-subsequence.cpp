class Solution {
    int helper(string text1, int ind1,string text2, int ind2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2]){
            return dp[ind1][ind2]=1+helper(text1,ind1-1,text2,ind2-1,dp);
        }
        if(text1[ind1]!=text2[ind2])
            return dp[ind1][ind2]=max(helper(text1,ind1-1,text2,ind2,dp),helper(text1,ind1,text2,ind2-1,dp));
            return dp[ind1][ind2]=0;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return helper(text1,text1.length()-1,text2,text2.length()-1,dp);
       int i=0;
       int j=0;
    //    if(text1[i]==text2[j])
    //     dp[i][j]=1;
        
        for( i=1;i<=text1.size();i++){
            for( j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[i-1][j-1];
    }
};