class Node{
private:
Node *link[26];
bool flag=false;
public:

 bool containsKey(char ch){
     return link[ch-'a']!=NULL;
 }
 void put(char ch,Node *node){
     link[ch-'a']=node;
 }
 Node* get(char ch){
     
     return link[ch-'a'];
 }
bool isEnd(){
    return flag;
 }
 void setEnd(){
    flag=true;
 }
};


class Trie {

    Node* root;
public:
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node= root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
                
            
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
           node=node->get(word[i]); 
        
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i]))
               { return false;}
            node=node->get(prefix[i]); 
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */