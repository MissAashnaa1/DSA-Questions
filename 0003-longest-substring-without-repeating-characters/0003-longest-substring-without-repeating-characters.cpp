class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
    int i=0;
    int j=0;
    int maxl=0;
    map<char,int>m;
    // while(j<s.length()){
    //     m[s[j]]++;
    //     if(j-i+1==m.size()){
    //     maxl=max(maxl,j-i+1);
        
    //     }
    //     else {
    //         while(j-i+1!=m.size()){
    //              m[s[i]]--;
    //         if(m[s[i]]==0){
    //           m.erase(s[i]);
    //             }
    //         i++;
    //         }
    //     }
    //     j++;
    // }
    while(j<s.length()){
        if(m.find(s[j])!=m.end()){
            i = max(i, m[s[j]] + 1);
        }
        m[s[j]]=j;
        maxl=max(maxl,j-i+1);
        j++;
    }
    return maxl;
    }
};