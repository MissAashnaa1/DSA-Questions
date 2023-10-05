//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int n=str1.length();
        int m=str2.length();
        int i=0;
        int j=0;
        int k=0;
        //3 ptr
        int start=-1;
        int minlen=1e7;
        while(j<n&&k<m){
            if(str1[j]==str2[k]){
                k++;
                
            }
            // cout<<i<<" "<<j<<endl;
            if(k==m){
                i=j;
                k=m-1;
                while(i>=0&&k>=0){
                    if(str1[i]==str2[k]){
                        k--;
                    }
                   
                    i--;
                    // cout<<i<<endl;
                }
                i++;
                // cout<<i<<endl;
                if(minlen>j-i+1){
                    start=i;
                    minlen=j-i+1;
                    str1.substr(start,minlen);
                }
                j=i+1;
                k=0;
            }
            j++;
        }
        if(start==-1){
            return "";
        }
        return str1.substr(start,minlen);
       
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends