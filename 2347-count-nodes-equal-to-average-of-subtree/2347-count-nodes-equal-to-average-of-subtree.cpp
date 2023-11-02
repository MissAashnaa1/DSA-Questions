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

    pair<int,int> helper(TreeNode* root,int &ans,int count){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> lef=helper(root->left,ans,count-1);
        pair<int,int> righ=helper(root->right,ans,count+1);
        if((lef.first+righ.first+root->val)/(1+abs(lef.second)+abs(righ.second))==root->val){
            ans++;
        }
        return {lef.first+righ.first+root->val,(1+abs(lef.second)+abs(righ.second))};
        
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        helper(root,ans,0);
        return ans;
    }
};