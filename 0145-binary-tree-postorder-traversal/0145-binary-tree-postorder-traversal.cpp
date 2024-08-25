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
    // void post(TreeNode* root,vector<int>&v){
    //     if(root==NULL){
    //         return;
    //     }
    //     post(root->left,v);
    //     post(root->right,v);
    //     v.push_back(root->val);
    // }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>v;
        // post(root,v);
        // return v;
        if(!root){
            return {};
        }
        stack<TreeNode*>st1;
        
         vector<int>v;
        st1.push(root);
        while(st1.size()){
            TreeNode* node=st1.top();
            v.push_back(node->val);
            st1.pop();
            if(node->left){
                st1.push(node->left);

            }
            if(node->right){
                st1.push(node->right);
            }
        }
       
        reverse(v.begin(),v.end());
        
        return v;
    }

};