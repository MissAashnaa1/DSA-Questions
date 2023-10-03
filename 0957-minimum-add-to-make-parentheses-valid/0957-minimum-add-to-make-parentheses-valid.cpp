class Solution {
public:
    int minAddToMakeValid(string s) {
          
    stack <char> st;
    int count=0;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            if(st.empty()==true){
                count++;
                
            }
            else {
                 st.pop();
            }
        }
        else if(s[i]=='(')
        {
            st.push('(');
            
        }
    }
   
    int g=st.size();
     
    return count+g;
    }
};