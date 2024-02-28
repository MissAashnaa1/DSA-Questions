//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
     private:
    int charToInt(char ch)
    {
        int ans = ch - '0';
        return ans;
    }
    public:
    int DivisibleByEight(string s){
        
        int number = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            int digit = charToInt(s[i]);
            number = (number * 10) + digit;
        }
        
        if(number % 8 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends