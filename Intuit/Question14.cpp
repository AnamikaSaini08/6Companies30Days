int dir[4][2] = { {-1,0} , {1,0} , {0,1} , {0,-1}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        queue<pair<int,int>>q;
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>>dist_ans(row , vector<int>(col,INT_MAX));
        
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                if(grid[i][j]){
                    q.push({i,j});
                    dist_ans[i][j] = 0;
                }
            }
        }
        while(q.size())
        {
            auto temp = q.front();
            int x = temp.first;
            int y = temp.second;
            q.pop();
            
            for(int i=0 ; i<4 ; i++)
            {
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                
                if(xx>=0 && xx<row && yy>=0 && yy<col)
                {
                    if(dist_ans[xx][yy] == INT_MAX )
                    {
                       
                        dist_ans[xx][yy] = dist_ans[x][y]+1;
                        q.push({xx,yy});
                    }
                }
            }
        }
        
        int mx = INT_MIN;
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                if(grid[i][j])
                    dist_ans[j][j] = 0;
                mx = max(mx , dist_ans[i][j]);
            }
        }
        if(mx == INT_MIN || mx == INT_MAX || mx == 0)
            return -1;
        return mx;
    }