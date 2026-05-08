class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length; int m = matrix[0].length;
        int r = 0; int c = m-1;

        while(r<n && c>=0){
            if(target == matrix[r][c]){
                return true;
            }

            else if(target<matrix[r][c]){
                c--;

            }
            else{
                r++;
            }
        }
        return false;
        
    }
}