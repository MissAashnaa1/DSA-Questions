//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string temp="";
       while(r>0){
         for(int i=0;i<n+2;i++){
             if(s[i]=='1'){
                 temp +="10";
             }
             else{
                 temp+="01";
             }
         }
         s=temp;
         temp="";
       r--;
       }
       return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends