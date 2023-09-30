class Solution {
    bool helper(int i,int j,vector<int>& nums,int p1,int p2,bool turn){
        if(i>j)
            return p1>=p2;
           
        if(turn){
            return helper(i+1,j,nums,p1+nums[i],p2,!turn)||
            helper(i,j-1,nums,p1+nums[j],p2,!turn);
        }
        else {
            return helper(i+1,j,nums,p1,p2+nums[i],!turn)&&
            helper(i,j-1,nums,p1,p2+nums[j],!turn);
        }

    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return helper(0,nums.size()-1,nums,0,0,true);
    }
};