class Solution {
    int helper(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        if(i<0){
            return j+1;//itne insert krne pdege
        }
        if(j<0){
            return i+1;//itne delete krne pdege
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=0+helper(word1,word2,i-1,j-1,dp);
        }
        else {
        int inser=1+helper(word1,word2,i,j-1,dp);
        int delet=1+helper(word1,word2,i-1,j,dp);
        int replace=1+helper(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(replace,min(inser,delet));
        }
        return -1;
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // return helper(word1,word2,word1.size()-1,word2.size()-1,dp);
    for(int i=0;i<=word1.length();i++){
        dp[i][0]=i;

    }
    for(int i=0;i<=word2.length();i++){
        dp[0][i]=i;
        
    }
    for(int i=1;i<=word1.length();i++){
        for(int j=1;j<= word2.length();j++){
            if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else{
                int inser=1+dp[i][j-1];
                int delet=1+dp[i-1][j];
                int replace=1+dp[i-1][j-1];
            dp[i][j]=min(replace,min(inser,delet));
            }
        }
    }
    return dp[word1.length()][word2.length()];
    }
};