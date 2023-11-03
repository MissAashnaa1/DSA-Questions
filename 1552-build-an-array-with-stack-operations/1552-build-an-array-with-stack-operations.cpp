class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int j=0;
        int trsize=target.size();
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(j>=trsize){
            
            break;
            }
        ans.push_back("Push");
        
         if(i!=target[j]){
            ans.push_back("Pop");
        }
        else{
            j++;
        }
        }
    return ans;
    }
};