class Solution {
public:
    string minWindow(string &s, string &t) {
       unsigned long long int start=0;
       unsigned long long int end=0;
       unsigned long long int minlen=s.length()+1;
       unsigned long long leaststart=-1;
       unsigned long long leastend=-1;
      string ans="";
      unordered_map<char,long long int>m;
      for(int i=0;i<t.length();i++){
        m[t[i]]++;
      }
      int countRequired=t.length();
      for(end=0;end<s.length();end++){
        if(m[s[end]]>0){
          countRequired--;
        }
        m[s[end]]--;
        if(countRequired==0&&minlen>end-start+1){
          minlen=end-start+1;
          leaststart=start;
          leastend=end;
        }
        while(countRequired==0){
          m[s[start]]++;
          if(m[s[start]]>0){
            countRequired++;
          }
          start++;
          if(countRequired==0&&minlen>end-start+1){
            minlen=end-start+1;
            leaststart=start;
          leastend=end;
          } 
        }

      }
      if(leaststart==-1){
        return "";
      }
      ans=s.substr(leaststart,leastend-leaststart+1);
      return ans;
    }
};