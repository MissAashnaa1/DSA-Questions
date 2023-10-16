class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        int n=nums2.size();
        unordered_map<int,int>m;
        m[nums2[n-1]]=-1;
        s.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&s.top()<nums2[i]){
                s.pop();
            }
            if(s.empty()){
                m.insert({nums2[i],-1});
            }
            else{
                m.insert({nums2[i],s.top()});
            }
            s.push(nums2[i]);
        }
        vector<int>v;
        for(auto  num: nums1){
            v.push_back(m[num]);
        }
        return v;
    }
};