//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool balanced(char x ,char y){
        
       if(x == '}' && y != '{') return false;
       if(x == '[' && y!= ']') return false;
       if(x == ')' && y != '(') return false;
    
      return true;
        
        
    }
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(int i = 0; i < x.length();i++){
            if(x[i] == '[' || x[i] == '('  || x[i] =='{')
             st.push(x[i]);
            else{
                if(!st.empty() && balanced(x[i],st.top())){
                    st.pop();
                }
                else
                 return false;
            }
        }
         if(st.empty()) return true;
         
         return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends