//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int n=S.length();
        int one=0;
        int zero=0;
        int two=0;
        int minLength=INT_MAX;
        int j=0;
        for(int i=0;i<n;i++){
            if(S[i]=='0'){
                zero++;
            }
            else if(S[i]=='1'){
                one++;
            }
            else if(S[i]=='2'){
                two++;
            }
            while(one>0&&two>0&&zero>0){
                minLength=min(minLength,i-j+1);
                if(S[j]=='0'){
                zero--;
                }
                else if(S[j]=='1'){
                one--;
                }
                else if(S[j]=='2'){
                two--;
                }
                j++;
                }
        }
        
        return minLength==INT_MAX?-1:minLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends