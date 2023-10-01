class Solution {
        int MArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>leftSmall(n,0);
        vector<int>rightSmall(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
            leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty())
            rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rightSmall[i]-leftSmall[i]+1)*heights[i]);
        }
        return ans;
        
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>height(matrix[0].size(),0);
        int maxAns=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else height[j]=0;
                
            }
            maxAns=max(maxAns,MArea(height));
        }
        return maxAns;
    }
};