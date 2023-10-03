class Solution {
    class Node{
       Node *link[2];
       public:
       bool containsKey(int index){
          return link[index]!=NULL;
       }
       Node* get(int index){
           return link[index];
       }
       void put(int index,Node *newnode){
            link[index]=newnode;
       }
     };
       class Trie{
           Node *root;
           public:
           Trie(){
               root=new Node();
           }
           void insert(int num){
               Node *node=root;
               for(int i=31;i>=0;i--){
                   int bit=(num>>i)&1;
                   if(!node->containsKey(bit)){
                       node->put(bit,new Node());
                   } 
                   node=node->get(bit);

               }
           }
           int getMax(int num){
               int maxNum=0;
               Node *node=root;
              for(int i=31;i>=0;i--){
                  int bit=(num>>i)&1;
                  if(node->containsKey(!bit)){
                     maxNum=maxNum|(1<<i);
                      node=node->get(!bit);
                  }
                  else{
                //    maxNum=maxNum|bit<<i;
                      node=node->get(bit);
                  }
              }
              
              return maxNum;
           }
       };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>>onlineQueries;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++){
            onlineQueries.push_back({ queries[i][1], { queries[i][0], i } });
        }
        sort(onlineQueries.begin(),onlineQueries.end());
        vector<int>ans(queries.size(),0);
        int ind=0;
        Trie trie;
        for(int i=0;i<queries.size();i++){
            int exorVal=onlineQueries[i].second.first;
            int k=onlineQueries[i].second.second;
            int maxValue=onlineQueries[i].first;
            while(ind<nums.size()&&nums[ind]<=maxValue){
                
                    trie.insert(nums[ind]);
                    ind++;
            
             }
                if(ind==0){
                    ans[k]=-1;
                }
                else {
                    ans[k]=trie.getMax(exorVal);
                }
           
        }
        return ans;
    }
};