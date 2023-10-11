class Solution {
    bool searchRow(vector<int>&arr,int target,int high){
        int low=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int high=matrix.size()-1;
        int m=matrix[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[mid][0]<=target&&target<=matrix[mid][m]){
                return searchRow(matrix[mid],target,m);
            }
            else if(matrix[mid][m]<=target){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        } 
        return false;
    }
};