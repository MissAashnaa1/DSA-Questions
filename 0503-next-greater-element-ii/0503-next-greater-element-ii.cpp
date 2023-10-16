class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
         stack<int>s;
        int n=nums2.size();
         vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums2[i]){
                s.pop();
            }
            
            s.push(nums2[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                v[i]=-1;
            }
            
            else {
                v[i]=s.top();
            }
            s.push(nums2[i]);
        }
        
        return v;
    }
    
};