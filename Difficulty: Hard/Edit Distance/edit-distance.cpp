//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];

        
        if(s[i]==t[j]){
            return dp[i][j]=solve(i-1, j-1, s, t, dp);
        }else{
            return dp[i][j]=1+min(solve(i-1, j-1, s, t, dp), 
            min(solve(i-1, j, s, t, dp), solve(i, j-1, s, t, dp)));
        }
    }
    
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.length(), m=s2.length();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, s1, s2, dp);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends