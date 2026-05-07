class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> ans = new ArrayList<>();

        int n = matrix.length;
        int m = matrix[0].length;

        int sr = 0;
        int er = n - 1;
        int sc = 0;
        int ec = m - 1;

        while (sr <= er && sc <= ec) {

            // top row
            for (int j = sc; j <= ec; j++) {
                ans.add(matrix[sr][j]);
            }

            // right column
            for (int i = sr + 1; i <= er; i++) {
                ans.add(matrix[i][ec]);
            }

            // bottom row
            if (sr < er) {
                for (int j = ec - 1; j >= sc; j--) {
                    ans.add(matrix[er][j]);
                }
            }

            // left column
            if (sc < ec) {
                for (int i = er - 1; i > sr; i--) {
                    ans.add(matrix[i][sc]);
                }
            }

            sr++;
            sc++;
            er--;
            ec--;
        }

        return ans;
    }
}