class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }

        int num;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] =='1'){
                    mark(i,j,grid);
                    num+=1;
                }
            }
        }
        return num;
    }
private:
    void mark(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1') return;
        grid[i][j]='0';
        mark(i-1,j,grid);
        mark(i,j-1,grid);
        mark(i,j+1,grid);
        mark(i+1,j,grid);
    }
};