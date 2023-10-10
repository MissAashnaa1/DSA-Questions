//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPossible(vector<int> &stall,int n,int k,int mid){
        //1 2 5 7 10\
        
        int prev=stall[0];
        int count=1;
        for(int i=1;i<n;i++){
            if(stall[i]-prev>=mid){
                count++;
                prev=stall[i];
            }
        }
        if(k<=count){
            return true;
        }
        return false;
    }
public:

    int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end());
    int low=INT_MAX;
    
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,stalls[i]);
        high=max(high,stalls[i]);
        
    }
    low=0;
    high-=low;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(stalls,n,k,mid)){
            low=mid+1;
            ans=mid;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends