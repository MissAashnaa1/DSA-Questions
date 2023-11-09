class Solution {
    const int mod=1e9+7;
public:
    int countHomogenous(string s) {
        char str='A';
        long long ans=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==str){
                len=(len+1)%mod;
                ans=(ans+len)%(mod);
            }
            else {
                ans+=1;
                str=s[i];
                len=1;
            }
        }
        return ans;
    }
};