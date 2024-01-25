//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isprime(int a){
        if(a<=1)return false;
        for(int i=2;i<=sqrt(a);i++){
            if(a%i==0)return false;
        }
        return true;
    }
    int solve(int a,int b)
    {   
        queue<pair<int,int>>q;
        unordered_map<int,int>m;
        q.push({a,0});
        m[a]++;
        while(q.size()){
            auto it=q.front();
            q.pop();
            if(it.first==b)return it.second;
            string s=to_string(it.first);
            for(int i=0;i<4;i++){
                char p=s[i];
                for(char o='0';o<='9';o++){
                    if((p!=o) && ((i==0 && o!='0')||(i!=0))){
                        s[i]=o;
                        int pp=stoi(s);
                        if(m.find(pp)==m.end() && isprime(pp)){
                            q.push({pp,it.second+1});
                            m[pp]++;
                        }
                    }
                }
                s[i]=p;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends