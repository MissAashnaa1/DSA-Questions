//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        if(s==0 and n==1) return "0";
        if(s==0) return "-1";
        string str="";
    while(n){
        
             if(s<=9){
            str+=to_string(s);
            n--;
            while(n){
                str+="0";
                n--;
            }
            return str;
        }
        else {
            s-=9;
            n--;
            str+="9";
        }
        
    }
        return"-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends