class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n=word1.length();
        int m=word2.length();
        int i=0;
        while(i<n&&i<m){
            ans+=word1[i];
            ans+=word2[i];
            i++;
        }
        ans+=word1.substr(i,n-i+1);
        ans+=word2.substr(i,m-i+1);
        return ans;
    }
};