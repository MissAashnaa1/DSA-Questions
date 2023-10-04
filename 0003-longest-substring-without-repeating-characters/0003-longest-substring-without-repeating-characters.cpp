class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    int maxl=0;
    map<char,int>m;
    while(j<s.length()){
        m[s[j]]++;
        if(j-i+1==m.size()){
        maxl=max(maxl,j-i+1);
        
        }
        else {
            while(j-i+1!=m.size()){
                 m[s[i]]--;
            if(m[s[i]]==0){
              m.erase(s[i]);
                }
            i++;
            }
        }
        j++;
    }
    return maxl;
    }
};