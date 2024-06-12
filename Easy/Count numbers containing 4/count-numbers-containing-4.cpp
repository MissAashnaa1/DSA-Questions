//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {

      int ans=0;
        for(int j=1;j<=n;j++)
        { int x=j;
            while(x>0)
            {  
               int r= x%10;
                if(r==4)
               { ans++;
               break;}
                x=x/10;
            }
        }
       
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends