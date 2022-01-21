int floodFill(int dx[] , int dy[] , int &ans ,  int x , int y ,int r , int c ,vector<vector<int>>& grid)
    {
        if(x<0 || x>=r || y<0 || y>=c)
            return 0;
        
        if(grid[x][y] !=1 )
            return 0;
            
        grid[x][y] = -1;
        ans++;
        
        for(int i=0 ; i<8 ; i++)
        {
            floodFill(dx , dy , ans , x+dx[i] , y+dy[i] , r,c,grid );
        }
    }
    
    
    
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans = INT_MIN;
        int r = grid.size();
        int c = grid[0].size();
        
        int dx[] = {-1 , 1 , 0 , 0 ,1 , 1 , -1 , -1};
        int dy[] = {0 , 0 , -1 , 1 , 1, -1 , 1 , -1 };
        
        for(int i=0 ; i<r ; i++)
        {
            for(int j=0; j<c ; j++)
            {
                int res = 0;
                if(grid[i][j]==1)
                {
                    floodFill(dx , dy ,res , i,j,r,c,grid);
                    ans = max(ans,res);
                }
            }
        }
        return ans;
    }