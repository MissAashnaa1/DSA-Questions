//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
           int s = 0;
        int n = a.size();
        int e = a.size() - 1;
        
        int maxi = INT_MIN;
        while(s <= e){
            int mid = (s+e)/2;
            
            if(mid+1 < n && a[mid] < a[mid+1]){
                maxi = max(maxi,a[mid+1]);
                s = mid+1;
            }
            else if(mid-1 >= 0 && a[mid-1] > a[mid]){
                maxi = max(maxi,a[mid-1]);
                e = mid-1;
            }
            else{
                maxi = max(maxi,a[mid]);
                break;
            }
            
        }
        return maxi;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends