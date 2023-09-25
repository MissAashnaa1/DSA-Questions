//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
       vector<vector<int> >v;
       int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0&&arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1&&arr[j]==arr[j-1]) continue;
                int target=k-arr[i]-arr[j];
                int l=j+1;
                int r=n-1;
                while(l<r){
                    long long sum=arr[l]+arr[r];
                    
                    if(sum>target){
                        r--;
                    }
                    else if(sum<target){
                        l++;
                    }
                    else{
                        vector<int>temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[l]);
                        temp.push_back(arr[r]);
                        v.push_back(temp);
                         while(l<r && arr[l] == temp[2]) ++l;
                         while(l<r && arr[r] == temp[3]) --r;
                        //  l++;
                        //  r--;
                    }
                }
            }
           
        }
         return v;
    }
    
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends