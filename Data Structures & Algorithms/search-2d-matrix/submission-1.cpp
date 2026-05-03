class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS=matrix.size(),COLS=matrix[0].size();
        int top=0,bot=ROWS-1;
        while(top<=bot){
            int row = (top+bot)/2;
            if( target > matrix[row][COLS-1]){
                top= row+1;
            }
            else if(target < matrix[row][0]){
                bot=row-1;
            }
            else{
                break;
            }
        }
        if(top>bot){
            return false;
        }
        int l=0,r=COLS-1;
        int row = (top+bot)/2;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[row][mid]<target){
                l=mid+1;
            }
            else if (matrix[row][mid]>target) {
                r=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
        
    }
};
