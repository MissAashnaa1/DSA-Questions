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
    int heightl(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;

        }
        return h;
    }
     int heightr(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;

        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lefth=heightl(root);
        int righth=heightr(root);
        if(lefth==righth){
            return pow(2,lefth)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};