//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
    bool static comp(pair<int,int> a,pair<int,int> b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            int diff=abs(arr[i]-x);
            if(diff==0){
                continue;
            }
            if(pq.size()<k){
                pq.push({diff,arr[i]});
            }
            else{
                if(pq.top().first>=diff){
                    pq.pop();
                    pq.push({diff,arr[i]});
                }
            }
        }
        vector<pair<int,int>>ans;
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        sort(ans.begin(),ans.end(),comp);
        int i=0;
        vector<int>v;
        while(i<ans.size()){
            v.push_back(ans[i].second);
            i++;
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends