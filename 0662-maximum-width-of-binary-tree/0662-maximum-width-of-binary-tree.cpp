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
 #include<bits/stdc++.h>
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
     long long int ans=0;
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
      
        
        while(!q.empty()){
            int size=q.size();
            
           int start=q.front().second;
           long long  minn=LONG_MAX;
           long long  maxx=LONG_MIN;
            for(int i=0;i<size;i++){
                
                TreeNode * cur=q.front().first;

                long long level=q.front().second-start;
                minn=min(level,minn);
                maxx=max(level,maxx);
                q.pop();
               
                
                if(cur->left)
                q.push({cur->left,2*level});
                
                if(cur->right)
                q.push({cur->right,2*level+1});
                
                
            }

          long long int temp = maxx-minn;
          ans=max(ans,temp);
            
        }
        return ans+1;
    }
};