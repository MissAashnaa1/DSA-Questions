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
    TreeNode* func(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder,int inStart,int inEnd,map<int,int>&m){
        if(preStart>preEnd||inStart>inEnd){
            return NULL;
        }
        int pos=m[preorder[preStart]];
        int ele=pos-inStart;
        TreeNode* node=new TreeNode(preorder[preStart]);
        node->left=func(preorder,preStart+1,preStart+ele,inorder,inStart,pos-1,m);
        node->right=func(preorder,preStart+ele+1,preEnd,inorder,pos+1,inEnd,m);

    return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>map;
        for(int it=0;it<inorder.size(); it++)
            map[inorder[it]]=it;
        return func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
    }
};