//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
        string last="1";
        string newS;
        for(int k=2;k<=n;k++){
            
            int i=0;
            int j=0;
            while(j<last.length()){
                //counting string
                
                while(last[i]==last[j]&&j<last.length()){
                    j++;
                }
                    int count=j-i;
                    newS+=to_string(count)+last[i];
                    i=j;
                
            
            }
            last=newS;
            newS="";

        }
        return last;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends