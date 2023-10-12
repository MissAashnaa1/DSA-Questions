class Solution {
    int upper_bound(vector<int>&row,int m,int target){
        int low=0;
        int high=m-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(row[mid]<=target){
                ans=mid;
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans+1;
    }
    int smallerThan(vector<vector<int>> &matrix, int n, int m,int mid){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=upper_bound(matrix[i],m,mid);
        }
        return ans;
    }
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=INT_MAX;
        int high=INT_MIN;
        
        for(int i=0;i<n;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][m-1]);
        }
        int ans=-1;
        int req=k;
        while(low<=high){
            int mid=low+(high-low)/2;
            int ele=smallerThan(matrix,n,m,mid);
            if(ele<req){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
            
        }
        return ans;
    }
};