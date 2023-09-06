//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>dis(100001,1e9);
        queue<pair<int,int>>q;
        q.push({0,start});
        int mod=100000;
        if(start == end)
            return 0;
        while(!q.empty()){
            
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto it: arr){
                int num=it*node%mod;
                 if(num==end)
                        return steps+1;
                if(steps+1<dis[num]){
                   
                    q.push({steps+1,num});
                    dis[num]=steps+1;
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends