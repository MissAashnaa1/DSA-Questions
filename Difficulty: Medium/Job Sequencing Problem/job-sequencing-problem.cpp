//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
   
    //Function to find the maximum profit and the number of jobs done.
      public:
    static bool cmp(const pair<int,int>&a, const pair<int,int> &b)
    {
        if(a.first==b.first)
        return a.second>b.second;
        
        return a.first<b.first;
    }
    static bool cmp1(const pair<int,int>&a, const pair<int,int> &b)
    {
        if(a.second==b.second)
        return a.first<b.first;
        
        return a.second>b.second;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i].dead,arr[i].profit});
        }
        sort(v.begin(),v.end(),cmp);
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, decltype(&cmp1) >pq(cmp1);
        
        vector<int>x;
        int t=1;
        for(auto it:v)
        {
            if(it.first>=t)
            {
                pq.push(it);
                t++;
            }
            else 
            {
                if(!pq.empty() && it.second>pq.top().second)
                {
                    pq.pop();
                    pq.push(it);
                }
            }
        }
        
        int count=0;
        int sum=0;
        while(!pq.empty())
        {
            count++;
            sum+=pq.top().second;
            pq.pop();
        }
        x.push_back(count);
        x.push_back(sum);
        return x;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends