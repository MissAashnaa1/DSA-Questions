class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>m;
        vector<int>v;
        for(int i=0;i<arr1.size();i++){
            m[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(m[arr2[i]]){
                v.push_back(arr2[i]);
                m[arr2[i]]--;
            }
        }
        vector<int>left;
        for(auto it:m){
            while(it.second){
                left.push_back(it.first);
                it.second--;
            }
            
        }
        sort(left.begin(),left.end());
        for(int i=0;i<left.size();i++){
            v.push_back(left[i]);
        }
        return v;
    }
};