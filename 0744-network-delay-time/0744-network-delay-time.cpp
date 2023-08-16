class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
          for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
            

        }
        set<pair<int,int>>s;
        s.insert({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        while(!s.empty()){
            auto top=*s.begin();
            int curDist=top.first;
            int node=top.second;
            s.erase({curDist,node});
            
            for(auto nbr: adj[node]){
                int adjNode=nbr.first;
                int adjwt=nbr.second;
                if(curDist+adjwt<time[adjNode]){
                    if(time[adjNode]!=INT_MAX)
                    s.erase({time[adjNode],adjNode});//vo vha ni jyega fr 
                    
                    time[adjNode]=adjwt+curDist;
                    
                    s.insert({time[adjNode],adjNode});
                }
                
            }
            
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            
            if(time[i]==INT_MAX){
                return -1;
            }
                
            ans=max(ans,time[i]);
        }
        return ans;
    }
};