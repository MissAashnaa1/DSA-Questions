//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(d==1){
            if(s>9) return "-1";
            
        }
        // code here
        string start="1";
        int no_zeros=d-1;
        while(no_zeros--){
            start+='0';
        }
        // cout<<start<<endl;
       int start1=stoi(start);
        while(start1<INT_MAX){
            
            int number=start1;
            int sum=0;
            while(number!=0){
                int ld=number%10;
                sum+=ld;
                number/=10;
            }
            if(sum==s) return to_string(start1);
            if(to_string(start1).length()>d) return "-1";
            start1++;
        }
        return start;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends