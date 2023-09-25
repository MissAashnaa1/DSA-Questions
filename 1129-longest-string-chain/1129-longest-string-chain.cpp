class Solution {
    bool check(string s1,string s2){
        if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
    }
    bool static comp(string& s1, string& s2){
    return s1.size() < s2.size();
}

public:
    int longestStrChain(vector<string>& words) {
        //sort
        //compare all to prev ki ek letter  k gap h kya
        int maxo=1;
        sort(words.begin(),words.end(),comp);
        vector<int>dp(words.size(),1);

        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(dp[prev]+1>dp[i]&&check(words[i],words[prev])){
                    dp[i]=dp[prev]+1;
                    
                }

            }
            maxo= max(dp[i],maxo);
        }
        return maxo;
    }
};