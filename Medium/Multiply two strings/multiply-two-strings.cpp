//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
     string multiplyStrings(string s1, string s2) {
       //Your code here
       int first=s1.length();
       int last=s2.length();
       string str(first+last,'0');
       int g=0,l=0;
       if(s1[0]=='-') g=1;
       if(s2[0]=='-') l=1;
       for(int i=first-1;i>=g;i--){
           for(int j=last-1;j>=l;j--){
               int p=(s1[i]-'0')*(s2[j]-'0')+(str[i+j+1]-'0');
               str[i+j+1]=p%10+'0';
               str[i+j]+=p/10;
           }
       }
       for(int i=0;i<first+last;i++)
       if(str[i]!='0'){
           if((g==1 && l==0)||(g==0 && l==1))
           return '-'+str.substr(i);
           return str.substr(i);
       }
        
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends