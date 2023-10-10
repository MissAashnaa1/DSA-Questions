//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int power(int num, int pow, int comp){
	    long long int result = 1;
        for (int i = 0; i < pow; i++) {
            result *= num;
            if(result>comp){
                return 2;
            }
        }
        if(result==comp) return 1;
        return 0;
	}
	
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int lo=1;
	    int hi=m;
	    
	    while(lo<=hi){
	        int mid=lo+(hi-lo)/2;
	        
	        int midWithPower=power(mid, n, m);
	        if(midWithPower==1){
	            return mid;
	        }
	        else if(midWithPower==0){
	            lo=mid+1;
	        }else{
	            hi=mid-1;
	        }
	    }
	    return -1;
	} 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends