class Solution {
    bool help(string str,int ind,set<string>s,vector<int>&dp){
        if(ind==str.length())
            return 1;
        if(dp[ind]!=-1)
        return dp[ind];
        string temp="";
        for(int i=ind;i<str.length();i++){
            temp+=str[i];
            if(s.find(temp)!=s.end()){
                if(help(str,i+1,s,dp))
                    return dp[ind]=1;
            }
        }
        return dp[ind]=0;
    }
public:
    bool wordBreak(string str, vector<string>& w) {
        set<string>s;
        vector<int>dp(str.length()+1,-1);
        for(auto it:w){ 
            s.insert(it);
        }
        
       return help(str,0,s,dp);
    //    return dp[str.length()];
    }
};