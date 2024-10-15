class Solution {
public:
    long long minimumSteps(string s) {
        
        int len = s.length();
        int black = 0;
        long steps = 0;
        
        for(int i=0;i<len;i++) {
            if(s[i]=='1') {
                black++;
            }
            else {
                steps += black;
            }
        }
        
       
    // Count the number of black balls
    

    return steps;
    }
};