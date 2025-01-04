class Solution {
public:
    int countPalindromicSubsequence(string s) {
          unordered_map<char,int>first;
        unordered_map<char,int>last;
        unordered_map<char,int>cnt;
        // store first ,last and frequency in respective maps
        for(int i=0;i<s.length();i++){
            cnt[s[i]]++;
            last[s[i]]=i;
            if(!first.count(s[i]))
                first[s[i]]=i;
        }
        
        int ans=0;
        
        for(auto &[ch,f] : cnt )
        {
            if(f>=2){//pallidrome will form whenever first and last character are same
                int left = first[ch] , right = last[ch];
                unordered_set<int> uniq;//stores all unique characters between first and last 
                for(int i = left + 1 ; i < right ; i++){
                    uniq.insert(s[i]);
                }
                ans += uniq.size();//size of set tells us the middle letter candidates for pallidrome
            }
        }
        return ans;
        
    
    }
};