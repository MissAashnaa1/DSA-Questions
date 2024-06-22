//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long ans = -1;
        bool flag = false;           // to check if 9 is present or not 
        long long temp = 0;          // to store current number
        
        for(int i = 0; i < sentence.size(); i++)
        {
            if(sentence[i] - '0' >= 0 && sentence[i]-'0' <= 9)
            {
                temp = temp*10 + sentence[i]-'0';
                
                if(sentence[i]-'0' == 9) {
                    flag = true;
                }
            }
            
            if(sentence[i] == ' ' && temp != 0)
            {
                if(!flag)
                {
                    ans = max(ans, temp);
                    temp = 0;  
                }
                else{
                    temp = 0;
                    flag = false;
                }
                
            }
        }
        
        // for last number if exit at  the end of string
        if(temp != 0 && !flag)
            {
                ans = max(ans, temp);
            }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends