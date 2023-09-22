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
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return helper(word1,word2,word1.size()-1,word2.size()-1,dp);

    }
};