class NumMatrix {
public:
    vector<vector<int>> grid;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        grid = matrix;
        for(int i = 1 ; i < n ; i++) {
            grid[i][0] += grid[i-1][0];
        }

        for(int i = 1 ; i < m; i++) {
            grid[0][i] += grid[0][i-1];
        }
        
        for(int i = 1 ; i < n ; i++) {
            for(int j = 1 ; j < m ; j++) {
                grid[i][j] = matrix[i][j] + grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = grid[row2][col2];
        int top = ((row1 > 0) ? grid[row1-1][col2] : 0);
        int left = ((col1 > 0 ) ? grid[row2][col1-1] : 0);
        int lefttop = ((row1>0 && col1>0) ? grid[row1-1][col1-1] : 0);
        
        return  total - top - left + lefttop;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */