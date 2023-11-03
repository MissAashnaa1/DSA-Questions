//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    void inorder(Node* root,unordered_map<Node*,Node*>&m){
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
    void getNodes(Node*root,Node* target,unordered_map<Node*,Node*>m,int &time){
        queue<pair<Node*,int>>q;
        q.push({target,0});
        unordered_set<Node*>s;
        s.insert(target);
        int level=0;
        s.insert(NULL);
        s.insert(m[root]);
        while(q.size()){
            Node* node=q.front().first;
            level=q.front().second;
            q.pop();
            time=max(time,level);
            
                if(s.find(node->left)==s.end()){
                    q.push({node->left,level+1});
                    s.insert(node->left);
                }
                if(s.find(node->right)==s.end()){
                    q.push({node->right,level+1});
                    s.insert(node->right);
                }
                
                if(s.find(m[node])==s.end()){
                    q.push({m[node],level+1});
                    s.insert(m[node]);
                }
            
        }
        
      
    }

    Node* getTarget(Node* root,int target){
        if(!root){
            return root;
        }
        if(root->data==target){
            return root;
        }
        Node *lef=getTarget(root->left,target);
        Node* righ=getTarget(root->right,target);
        if(lef){
            return lef;
        }
        if(righ){
            return righ;
        }
        return NULL;
    }
  public:
    int minTime(Node* root, int target) 
    {
         unordered_map<Node*,Node*>m;
        m[root]=new Node(-1);
        inorder(root,m);
       
        int time=0;
        Node* Target=getTarget(root,target);
        getNodes(root,Target,m,time);
        return time;
        
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends