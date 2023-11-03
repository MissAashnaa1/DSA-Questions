/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&m){
        if(!root){
            return;
        }
        if(root->left){
            m[root->left]=root;
            inorder(root->left,m);
        }
        if(root->right){
            m[root->right]=root;
            inorder(root->right,m);
        }

    }
    void getNodes(TreeNode*root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>m,int k,vector<int>&v){
        queue<pair<TreeNode*,int>>q;
        q.push({target,k});
        set<TreeNode*>s;
        s.insert(target);
        int level=k;
        s.insert(NULL);
        s.insert(m[root]);
        while(q.size()){
            TreeNode* node=q.front().first;
            level=q.front().second;
            q.pop();
            if(level==0){
                v.push_back(node->val);
            
            }
            else{
                if(s.find(node->left)==s.end()){
                    q.push({node->left,level-1});
                    s.insert(node->left);
                }
                if(s.find(node->right)==s.end()){
                    q.push({node->right,level-1});
                    s.insert(node->right);
                }
                
                if(s.find(m[node])==s.end()){
                    q.push({m[node],level-1});
                    s.insert(m[node]);
                }
            }
        }
       
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>m;
        m[root]=new TreeNode(-1);
        inorder(root,m);
        vector<int>v;
        getNodes(root,target,m,k,v);
        return v;

    }
};