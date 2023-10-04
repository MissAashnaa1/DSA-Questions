class Solution {
public:
    int characterReplacement(string s, int k) {
     int i=0;
    int j=0;
    int maxl=0;
    int maxi=0;
    unordered_map<char,int>m;
    while(j<s.length()){
        m[s[j]]++;
        maxi=max(m[s[j]],maxi);
        
      while((j-i+1)-maxi>k){
             m[s[i]]--;
        if(m[s[i]]==0){
          m.erase(s[i]);
            }
        i++;
        }
        
        maxl=max(maxl,j-i+1);
        j++;
    }
    return maxl;
    }
};