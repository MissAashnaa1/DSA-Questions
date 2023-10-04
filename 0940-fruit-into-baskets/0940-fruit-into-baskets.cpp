class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int i=0;
    int j=0;
    int maxl=0;
    unordered_map<int,int>m;
    while(j<fruits.size()){
    
        m[fruits[j]]++;
    
            while(m.size()>2){
                 m[fruits[i]]--;
                
            if(m[fruits[i]]==0){
              m.erase(fruits[i]);
                }
            i++;
            }
        
        maxl=max(maxl,j-i+1);
        j++;
    }
    return maxl;
    }
};