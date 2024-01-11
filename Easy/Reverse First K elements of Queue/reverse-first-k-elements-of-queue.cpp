//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> st;
        //pushing first k element into stack
        for(int i=0;i<k;i++)
        {    
           st.push(q.front());
            q.pop();
           
        }
        //creating vector to store remaining elemetn of queue
        vector<int> v;
        while(!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
        
        
        //pushing stack element into  queue
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        //now push all element of vector which is in seme position
        for(int i=0;i<v.size();i++)
        {
            q.push(v[i]);
        }
        return q;
    
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends