void dfs(char** grid,int x,int y,int gridSize,int*gridColSize){
    if(x<0 || x>=gridSize || y<0 || y>=gridColSize[x])return;
    if(grid[x][y] == '0')return;
    grid[x][y] = '0';
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    for(int i=0;i<4;i++){
        dfs(grid,x+dx[i],y+dy[i],gridSize,gridColSize);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridColSize[i];j++){
            if(grid[i][j] == '1')count++;
            dfs(grid,i,j,gridSize,gridColSize);
        }
    }
    return count;
}