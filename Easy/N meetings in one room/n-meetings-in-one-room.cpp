//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int S[], int F[], int n)
    {
        // Your code here
            vector<pair<int,int>> v;
      //  vector<int> ans;
        for(int i=0;i<n;i++)
        {
            v.push_back({S[i],F[i]});
        }
        sort(v.begin(),v.end(),custom);
      int ans=1;
        int prev=v[0].second;
        for(int i=1;i<v.size();i++)
        {
            
            if(v[i].first>prev)
            {
                ans++;
                // cout<<v[i].first<<" "<<v[i].second;
                prev=v[i].second;
            }
        }
       
        return ans;
    }
    static bool custom(pair<int,int> a, pair<int,int> b)
    {
        if(a.second!=b.second)
        return a.second<b.second;
        return a.first<b.first;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends