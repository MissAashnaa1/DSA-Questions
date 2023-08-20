//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	     int i=0;
       int zero=0;
	   int max0=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='0')
				++zero;
				else --zero;
				max0=max(max0,zero);
				if(zero<0)
					zero=0;

		}
	if(max0==0)	
		return -1;
		return max0;
       
	}
	
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends