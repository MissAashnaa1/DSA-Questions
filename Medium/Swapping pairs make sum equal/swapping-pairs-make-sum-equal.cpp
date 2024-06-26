//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here  int findSwapValues(int a[], int n, int b[], int m) 
    {
        int s1 = 0;
        int s2 = 0;
        for(int i = 0; i < n; i++) s1 += a[i];
        for(int i = 0; i < m; i++) s2 += b[i];
        int diff = s1-s2;
        if(diff%2 != 0)
        {
            return -1;
        }
        if(s1 < s2)
        {
            swap(a,b);
            swap(n,m);
        }
        set<int> s;
        sort(a,a+n);
        for(int i = 0; i < m; i++)
        {
            auto ind = upper_bound(a,a+n,b[i]+abs(diff)/2);
            ind--;
            if(*ind == b[i]+abs(diff)/2)
            {
                return 1;
            }
        }
        return -1;
    }
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends