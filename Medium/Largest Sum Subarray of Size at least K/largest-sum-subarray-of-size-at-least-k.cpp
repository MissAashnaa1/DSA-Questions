//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int arr[], long long int n, long long int k) 
    {
        
        
        int ws=0,we=0;
      long long res = -1e9 ,curr=0;
      long long temp=0;
      for(;we<n;we++)
      {
          curr += arr[we];
          int windowSz = we-ws+1;
          if(windowSz==k)
            res = max(res,curr);
          else if(windowSz>k)
          {
              temp += arr[ws];
              ws++;
              if(temp<0)
              {
                  curr-=temp;
                  temp=0;
              }
              res = max(res,curr);
          }
      }
      return res;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends