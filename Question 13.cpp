int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        int visit[m][n] , tm=0;
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                visit[i][j] = 0;
            }
        }
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if( grid[i][j] == 0){
                    visit[i][j] = 1;
                }
                
                else if(grid[i][j] == 2)
                {
                    q.push({i,j});
                    visit[i][j] = 1;
                }
            }
        }
        
        while(!q.empty())
        {
            
            int count = 0 , size = q.size() , i=1;
            while(i<=size)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                if( (x-1) >= 0)
                {
                    if(visit[x-1][y] != 1)
                    {
                        visit[x-1][y] = 1;
                        count=1;
                        q.push({x-1 , y});
                    }
                }
                
                if( (x+1) < m)
                {
                    if(visit[x+1][y] != 1)
                    {
                        visit[x+1][y] = 1;
                        count=1;
                        q.push({x+1 , y});
                    }
                }
                
                if( (y-1) >= 0)
                {
                    if(visit[x][y-1] != 1)
                    {
                        visit[x][y-1] = 1;
                        count=1;
                        q.push({x , y-1});
                    }
                }
                
                if( (y+1) < n)
                {
                    if(visit[x][y+1] != 1)
                    {
                        visit[x][y+1] = 1;
                        count=1;
                        q.push({x , y+1});
                    }
                }
                
                i+=1;
            }
            
            if(count)
                tm++; 
        }
        
        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(visit[i][j] == 0)
                    return -1;
            }
        }
        return tm;
        
        
    }