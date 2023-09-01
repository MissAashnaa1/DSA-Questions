class Solution {
    bool isPalindrome(string str){
        int st=0;
        int end=str.length()-1;
        while(st<end){
            if(str[st]!=str[end])
                return false;
            st++;
            end--;
        }
        return true;
    }
    void helper(vector<vector<string>>&ans,vector<string>&v,string s,int index){
        if(index==s.length())
        {
            ans.push_back(v);
            return;
        }
        for(int i=index;i<s.length();i++){

            if(isPalindrome(s.substr(index,i-index+1)))
            {
                v.push_back(s.substr(index,i-index+1));
                helper(ans,v,s,i+1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
    vector<vector<string>>ans;
    vector<string>v;
    helper(ans,v,s,0);

        return ans;
    }
};