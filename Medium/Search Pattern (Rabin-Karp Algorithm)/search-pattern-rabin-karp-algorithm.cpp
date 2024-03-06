//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
         vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int>ans;
            string s;
            for(int i = 0;i<pattern.size();i++) s += text[i];
            if(s == pattern) ans.push_back(1);
            for(int i = pattern.size();i<text.size();i++){
                s.erase(0,1);
                s += text[i];
                if(s == pattern) ans.push_back(i-pattern.size()+2);
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends