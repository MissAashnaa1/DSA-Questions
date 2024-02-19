//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
   int wordBreak(string s, vector<string> &word) {
        vector<bool> dp(s.size()+1, 0);
        dp[0]=true;
        unordered_set<string> st(word.begin(), word.end());
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j, i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
            return dp[s.size()];
    }


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends