class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=INT_MIN;
        int r=INT_MAX;
        for(int i=0;i<left.size();i++){
            l=max(l,left[i]);
        }
        for(int i=0;i<right.size();i++){
            r=min(r,right[i]);
        }
        if(r==INT_MAX){
            return l;
        }
        return max(l,n-r);
    }
};