//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
       
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        vector<long long>ansarr;
        long long ans = 0;
        
        //Filling the Priority Queue
        for(int i = 0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        //Taking the sum of the top two elements of PQ and pushing them back 
        //Also taking the sum in ans array.
        while(pq.size()!=1){
            long long sum =pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            pq.push(sum);
            ansarr.push_back(sum);
        }
       
       //Adding elements of ans array and TADA!!!!!!!!!!!! thats the answer
        for(int i = 0;i<ansarr.size();i++){
            ans+=ansarr[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends