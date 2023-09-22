class Solution {
  int helper(string text1, string text2) {
     vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
       int i=0;
       int j=0;

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

public:
    int minDistance(string word1, string word2) {
        return word1.length()+word2.length()-2*helper(word1,word2);
    }
};