class Solution {
    int findMaxRow(vector<vector<int>>& mat,int col,int n){
       int index=-1;
       int maxEle=INT_MIN;
       for(int i=0;i<=n;i++){
           if(maxEle<mat[i][col]){
               maxEle=mat[i][col];
               index=i;
           }
       }
       return index;
        // int low=0;
        // int high=n;
        // while(low<=high){
        //     int mid=(low+high)/2;
            
        //     int up=-1;
        //     int down=-1;
            
               
        //         if(mid-1>=0){
        //             up=mat[mid-1][col];
        //         }
        //         if(mid+1<=n){
        //             down=mat[mid+1][col];
        //         }
        //     if(mat[mid][col]>up&&mat[mid][col]>down){
                
        //             return mid;
                
        //     }
        //     if(mat[mid][col]<up){
        //         high=mid-1;
                  
        //         }
        //         else{
        //              low=mid+1;
        //         }
        // }
        // return 0;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n=mat.size();
    int m=mat[0].size();

        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int up=-1;
            int down=-1;
            int right=-1;
            int left=-1;
            //row
           
            int index=findMaxRow(mat,mid,n-1);
             cout<<index<<' ';
                if(index-1>=0){
                    up=mat[index-1][mid];
                }
                if(index+1<n){
                    down=mat[index+1][mid];
                }
                if(mid-1>=0){
                    left=mat[index][mid-1];
                }
                if(mid+1<m){
                    right=mat[index][mid+1];
                }
            if(mat[index][mid]>right&&mat[index][mid]>left&&mat[index][mid]>up&&mat[index][mid]>down){
                
                    return {index,mid};
                
            }
            if(mat[index][mid]<left){
                high=mid-1;
                  
                }
                else{
                     low=mid+1;
                }
        }
       
        return {0,0};
    }
};