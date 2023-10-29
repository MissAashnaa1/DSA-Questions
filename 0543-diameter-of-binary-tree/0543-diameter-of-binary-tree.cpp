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
    int maxx=0;
    int height(TreeNode* root){
       if(root==NULL){
           return 0;
       }
       int l=height(root->left);
       int r=height(root->right);
        maxx=max(maxx,l+r+1);
       return 1+max(l,r);
   }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
    if(!root){
        return 0;
    }
    height(root);
    return maxx-1;
    }
};