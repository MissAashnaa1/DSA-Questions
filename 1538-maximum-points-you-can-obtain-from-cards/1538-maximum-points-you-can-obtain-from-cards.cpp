class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int i=0;
        int j=cardPoints.size()-1;
        int sum=0;
        for(i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        ans=max(ans,sum);
        i--;
        while(i>=0){
            sum-=cardPoints[i];
            i--;
            sum+=cardPoints[j];
            j--;
            ans=max(ans,sum);
        }
        return ans;
    }
};