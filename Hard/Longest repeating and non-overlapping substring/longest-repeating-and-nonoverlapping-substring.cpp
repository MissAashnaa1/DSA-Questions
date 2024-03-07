//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> lps(string &v)
{
    vector<int> ans(v.size(), 0);
    int len = 0;
    int ind = 1;
    while (ind < v.size())
    {
        if (v[ind] == v[len])
        {
            len++;
            ans[ind] = len;
            ind++;
        }
        else
        {
            if (len > 0)
            {
                len = ans[len - 1];
            }
            else
            {
                ind++;
            }
        }
    }
    return ans;
}
string longestSubstring(string s, int n)
{
    
    int ind = -1;
     int maxi =0;
    for (int i = 0; i < n; i++)
    {
        string news = s.substr(i);
        vector<int> LPS = lps(news);
        for (int j = 0; j < LPS.size(); j++)
        {
            if (LPS[j] > (j + 1) / 2)
            {
                int sz = (j + 1) / 2;
                if (sz > maxi)
                {
                    maxi = sz;
                    ind = i;
                }
            }
            else
            {
                int sz = LPS[j];
                if (sz > maxi)
                {
                    maxi = sz;
                    ind = i;
                }
            }
        }
    }
    // cout<<ind<<" "<<endl;
    if(ind!=-1)
    return s.substr(ind, maxi);
    else return "-1";
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends