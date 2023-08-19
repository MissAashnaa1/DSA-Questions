//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    int findParent(vector<int>&parent,int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent,parent[u]);
    }
    void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){
        int paru=findParent(parent,u);
        int parv=findParent(parent,v);
        if(rank[u]<rank[v]){
            parent[paru]=parv;
            
        }
        else if(rank[v]<rank[u]){
            parent[parv]=paru;
        }
        else{
            rank[v]++;
            parent[paru]=parv;
        }
    }
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        vector<int>rank(n,0);
        vector<int>parent(n,0);
        map<string,int>m;
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else{
                    unionSet(m[accounts[i][j]],i,parent,rank);
                }
            }
        }
        vector<vector<string>>ans;
        vector<string> merged[n];
        for(auto it:m){
            string mail=it.first;
            int node=findParent(parent,it.second);
            merged[node].push_back(mail);
        }
        for(int i=0;i<n;i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends