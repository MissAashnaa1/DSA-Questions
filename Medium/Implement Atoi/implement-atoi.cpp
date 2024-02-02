//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
  public:
    /*You are required to complete this method */
    void helper(string str,int &sum,int i){
        if(i>=str.length()){
            return ;
        }
        if(str[i]<'0'||str[i]>'9'){
            sum=-1;
            return;
        }
        sum=sum*10+(str[i]-'0');
        helper(str,sum,i+1);
    }
    int atoi(string str) {
        //Your code here
        int sum=0;
       
        if(str[0]=='-'){
            helper(str.substr(1),sum,0);
            if(sum==-1){
                return -1;
            }
            return sum*-1;
        }
        
        helper(str,sum,0);
        if(sum==-1){
                return -1;
            }
        return sum;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends