//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        
        map<long long ,long long> mp;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            long long temp = arr[i];
            while(temp)
            {
                if(temp&1)
                    mp[j]++;
                j++;
                temp = temp/2;
            }
        }
        for(int i = 0; i < 32; i++)
        {
            long long pairs = ((mp[i]-1) * mp[i]) / 2;
            ans += pairs * (long long)pow(2,i);
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends