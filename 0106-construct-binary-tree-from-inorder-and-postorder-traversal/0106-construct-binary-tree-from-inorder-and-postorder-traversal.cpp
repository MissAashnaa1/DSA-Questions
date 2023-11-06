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

TreeNode* func(vector<int>& postorder,int postStart,int postEnd, vector<int>& inorder,int inStart,int inEnd,map<int,int>&m){
        if(postStart<postEnd||inStart>inEnd){
            return NULL;
        }
        int pos=m[postorder[postStart]];
        int ele=pos-inStart;
        TreeNode* node=new TreeNode(postorder[postStart]);
        node->left=func(postorder,postEnd+ele-1,postEnd,inorder,inStart,pos-1,m);
        node->right=func(postorder,postStart-1,postEnd+ele,inorder,pos+1,inEnd,m);

    return node;
    }
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int,int>map;
        for(int it=0;it<inorder.size(); it++)
            map[inorder[it]]=it;
        return func(postorder,postorder.size()-1,0,inorder,0,inorder.size()-1,map);
    }
};