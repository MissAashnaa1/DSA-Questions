class Solution {
    long long fun(int x){
        if(x<0) return 0;
        long long ans=0;
        while(x){

            int last=x%10;
            ans=ans*10+last;
            x=x/10;
        }
        return ans;
    }
public:
    bool isPalindrome(int x) {
        
        int revX=fun(x);
        return revX==x;
    }
};