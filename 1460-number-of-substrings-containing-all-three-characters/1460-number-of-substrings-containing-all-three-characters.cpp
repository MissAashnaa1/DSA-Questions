class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0;
        int b=0;
        int c=0;
        int left=0;
        int ans=0;
        int right=0;
        while(right<s.length()){
            if(s[right]=='a'){
                a++;
            }
            else if(s[right]=='b'){
                b++;
            }
            else{
                c++;
            }
            while(a>0&&b>0&&c>0){
                ans+=s.length()-right;
                if(s[left]=='a'){
                    a--;
                }
                else if(s[left]=='b'){
                    b--;
                }
                else{
                    c--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};