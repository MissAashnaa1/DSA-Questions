class Solution {
public:
    string sortSentence(string s) {
        map<int,string>m;
        string str="";
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){

                m[s[i]]=str;
                
            }
            if(s[i]==' '){
                str="";
            }
            else{
                str+=s[i];
            }
        }
        string ans="";
        for(auto it:m){
            ans=ans+it.second;
            ans+=" ";
        }
        ans=ans.substr(0,ans.length()-1);
        return ans;
    }
};