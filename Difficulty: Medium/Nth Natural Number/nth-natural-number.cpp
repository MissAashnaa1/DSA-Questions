//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
        long long findNth(long long n) {
        // code here.
        
        long long ans=0, p=1;
        
        while(n)
        {
            ans += p*(n%9);
            n=n/9;
            p=p*10;
        }
        
        return ans;
        
      /*
      string s="";
        
         while(n)
         {
            long long x = n%9;
            s += to_string(x);
             n = n/9;
         }
         
        reverse(s.begin(), s.end());
        
        long long x = stoi(s);
        
        return x;
        */
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends