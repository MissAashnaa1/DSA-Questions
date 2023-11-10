//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int>s;
        string ans;
        int num=1;
        for(int i=0;i<S.length();i++){
            s.push(num++);
            if(S[i]=='I'){
                while(s.size()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
        s.push(num);
        while(s.size()){
            ans+=to_string(s.top());
            s.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends