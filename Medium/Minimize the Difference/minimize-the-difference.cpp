//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     int minimizeDifference(int n, int k, vector<int> &arr) {  

    vector<pair<int,int>> p, s;

    int mx1= INT_MIN, mi1= INT_MAX, mx2=INT_MIN , mi2 = INT_MAX; 

    for(int i=0; i<n-k; ++i){       

       if(arr[i] > mx1)mx1 = arr[i];   

       if(arr[i] < mi1 )mi1 = arr[i];

       if(arr[n-i-1] > mx2)mx2 = arr[n-i-1];

       if(arr[n-i-1] < mi2)mi2 = arr[n-i-1];

       p.push_back({mx1 , mi1});

       s.push_back({mx2 , mi2});

  }

  reverse(s.begin(), s.end());

     int i=0, j=0;

    int mx = s[0].first , mi = s[0].second;

    int ans = mx-mi;

   if(n == k+1) return 0;

    for(int i=0; i<n-k-1; ++i){

    mx = p[i].first , mi = p[i].second;

    if(s[i+1].first > mx)mx = s[i+1].first;

    if(s[i+1].second < mi)mi= s[i+1].second;

    ans= min(ans , mx-mi);

}

  return min(p[n-k-1].first-p[n-k-1].second , ans);

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends