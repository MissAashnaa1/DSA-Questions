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
                     maxNum=maxNum|1<<i;
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insert(nums[i]);
        }
        int maxNum=0;
        for(int i=0;i<nums.size();i++){
            maxNum=max(maxNum,trie.getMax(nums[i]));
        }
        return maxNum;
    }
};