class Solution {
public:
    int colcheck(vector<vector<int>>&matrix,int mid){
        int row=0;
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][mid]>matrix[row][mid]){
                row=i;
            }
        }
        return row;
    }
    vector<int>findPeakGrid(vector<vector<int>>&matrix) {
        int low=0;
        int high=matrix[0].size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=colcheck(matrix,mid);
            int left=(mid==0)?-1:matrix[row][mid-1];
            int right=(mid==(matrix[0].size()-1))?-1:matrix[row][mid+1];
            if(matrix[row][mid]>left && matrix[row][mid]>right){
                return{row,mid};
            }
            else if(matrix[row][mid]<left){
                high=mid-1;
            }
            else if(matrix[row][mid]<right){
                low=mid+1;
            }

        }
        return {-1,-1};

        
    }
};