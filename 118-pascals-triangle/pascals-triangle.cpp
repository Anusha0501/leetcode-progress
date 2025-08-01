class Solution {
public:
    // Generate the nth row (0-indexed) of Pascal's Triangle
    vector<int> generateRow(int rowIndex) {
        vector<int> row;
        long long val = 1;
        row.push_back(1);
        
        for (int col = 1; col <= rowIndex; col++) {
            val = val * (rowIndex - col + 1);
            val = val / col;
            row.push_back(val);
        }
        
        return row;
    }

    // Generate Pascal's Triangle with n rows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            triangle.push_back(generateRow(i));
        }
        return triangle;
    }
};