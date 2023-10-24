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
    vector < vector < int >> verticalTraversal(TreeNode * root) {
        map < int, map < int, multiset < int >>> nodes;
      // 1st vertical //2nd level  //multiset for taking in sorted order if same row and col
                                // gets second element

        /*
        What is a multiset in C++?
        Multisets in C++ are containers that are very similar to sets.
        Unlike sets, multisets can store duplicate elements in a sorted manner.
        */

        queue < pair < TreeNode * , pair < int, int >>> q;
        q.push({root,{0,0}}); //initial vertical and level
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode * temp = p.first;

            //x -> vertical , y->level
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(temp -> val); //inserting to multiset

            if (temp -> left) {
            q.push({temp -> left,{x - 1,y + 1}});
            }
            if (temp -> right) {
            q.push({temp -> right,{x + 1,y + 1}});
            }
        }

        vector < vector < int >> ans;
       for(auto it : nodes)
      {
          vector<int> temp;
          for(auto i : it.second)
          {
              for(auto j: i.second)
              {
                  temp.push_back(j);
              }
          }
          ans.push_back(temp);
      }
      return ans;
    
    }

   
};