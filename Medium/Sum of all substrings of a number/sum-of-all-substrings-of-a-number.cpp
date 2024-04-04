//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
       long long sumSubstrings(string s){
        long long n = s.size(), ans = 0, c = 1, x = 1, M = 1000000007;
        for (int i=n-1;i>=0;i--)
            ans = (ans + (i+1)*c%M*(s[i]-'0')%M)%M, x = (x*10)%M, c = (c+x)%M;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends