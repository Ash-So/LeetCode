class NumMatrix {
public:
    vector<vector<int>> sumMat;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        sumMat = matrix;
        
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(i>0) sumMat[i][j] += sumMat[i-1][j]; // add prev row
                if(j>0) sumMat[i][j] += sumMat[i][j-1]; // add prev col

                // remove diagonal as it is added twice above
                if(i>0&&j>0) sumMat[i][j] -= sumMat[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int answer = sumMat[row2][col2];

        if(row1>0) answer -= sumMat[row1-1][col2];  
        if(col1>0) answer -= sumMat[row2][col1-1]; 

        if(row1>0&&col1>0) answer += sumMat[row1-1][col1-1];
        return answer;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */