//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  int count(int n){
      int cnt=0;
      while(n>0){
          cnt+=n%10;
          n=n/10;
      }
      return cnt;
  }
    int smithNum(int n) {
        // code here
        int sum=count(n);
        int sp=0;
        int i=2;
        int t=n;
        while(i<n and t!=1){
            if(t%i==0){
                sp+=count(i);
                t=t/i;
            }
            else{
                i++;
            }
        }
        return sum==sp;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends