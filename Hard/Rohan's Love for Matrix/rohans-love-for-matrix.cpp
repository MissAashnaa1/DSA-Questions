//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
          if(n==1) return 1;
        
        long mod = 1000000007;
        long a00=1, a01=1, a10=1, a11=0;
        long b00=1, b01=1, b10=1, b11=0;
        
        for(int i=1; i<n; i++){
            long a = (a00*b00+a01*b10)%mod;
            long b = (a00*b01+a01*b11)%mod;
            long c = (a10*b00+a11*b10)%mod;
            long d = (a10*b01+a11*b11)%mod;
            a00 = a;
            a01 = b;
            a10 = c;
            a11 = d;
        }
        return (int)a10;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends