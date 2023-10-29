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
        int helper(TreeNode* root,int &maxx){
       if(root==NULL){
           return 0;
       }
       int l=max(0,helper(root->left,maxx));
       int r=max(0,helper(root->right,maxx));
        maxx=max(maxx,l+r+root->val);
       return root->val+max(l,r);
   }
    
public:
    int maxPathSum(TreeNode* root) {
        if(!root){
        return 0;
    }
    int maxx=INT_MIN;
    helper(root,maxx);
    return maxx;
    }
};