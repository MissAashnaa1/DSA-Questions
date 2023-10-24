/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
      
        map<int,int>m;
        while(!q.empty()){
            int size=q.size();
            
            vector<int>level;
           
            for(int i=0;i<size;i++){
                
                TreeNode * cur=q.front().second;
                int level=q.front().first;
                q.pop();
                m[level]=cur->val;
                
                
                if(cur->left)
                q.push({level+1,cur->left});
                
                if(cur->right)
                q.push({level+1,cur->right});
                
                
            }
         }
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
    
};