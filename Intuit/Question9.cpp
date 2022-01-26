int dir[4][2] = { {1,0} , {-1,0} , {0,1} , {0,-1} };
    void DFS(int x , int y , int prev, vector<vector<bool>>&ocean , vector<vector<int>>&heights , int row , int col)
    {
        if( x<0 || x>=row || y<0 || y>=col)  
            return;
        
        if(heights[x][y] < prev || ocean[x][y])
            return;
        
        ocean[x][y] = true;
        for(int i= 0 ; i<4 ; i++)
        {
            DFS(x+dir[i][0] , y+dir[i][1] , heights[x][y] , ocean , heights , row , col);
        }
        return;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int row = heights.size() , col = heights[0].size();
        
        vector<vector<bool>> pacific(row , vector<bool>(col , false));
        vector<vector<bool>>atlantic(row , vector<bool>(col , false));
        vector<vector<int>>ans;
        
        //DFS for pecific row - 0
        for(int i=0 ; i<col ; i++)
        {
            DFS( 0 , i , INT_MIN , pacific , heights ,  row , col);
            DFS( row-1 , i , INT_MIN , atlantic , heights ,  row , col);
        }
        //DFS for pecific col - 0
        for(int i=0 ; i<row ; i++)
        {
            DFS( i , 0 ,INT_MIN , pacific , heights ,  row , col);
            DFS( i , col-1 ,INT_MIN , atlantic , heights ,  row , col);
        }
        
        
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }