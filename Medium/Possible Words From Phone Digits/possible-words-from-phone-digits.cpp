//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
    
{    public:
    void helper(int a[],int ind,int n,vector<string> &ans,string str,vector<string>keypad){
    if(str.length()==n){
        ans.push_back(str);
        return;
    }
    string curr=keypad[a[ind]];
        for(int i=0;i<curr.length();i++){
            helper(a,ind+1,n,ans,str+curr[i],keypad);
        }
    
    }
   
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n )
    {
        //Your code here
        vector<string>ans;
        vector<string>keypad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(a,0,n,ans,"",keypad);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends