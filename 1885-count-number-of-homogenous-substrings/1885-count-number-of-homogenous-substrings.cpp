class Solution {
    const int mod=1e9+7;
public:
    int countHomogenous(string s) {
        string str="A";
        long long ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==str[0]){
                str+=s[i];
                ans=(ans+str.length())%(mod);
            }
            else {
                ans+=1;
                str=s[i];
            }
        }
        return ans;
    }
};