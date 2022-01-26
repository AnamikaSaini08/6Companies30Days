int dir[4][2] = { {-1,0} , {1,0} , {0,1} , {0,-1}};
    
    void DFS(int x , int y , int row , int col , int word_i , string &word , int n , vector<vector<char>>& grid , bool&ans ,string &op, vector<vector<bool>>&visit)
    {
        if(x<0 || x>=row || y<0 || y>=col || word_i >=n)
           return;
   
        if(grid[x][y] != word[word_i])
            return;
        if(visit[x][y])
            return;
        
        visit[x][y] = 1;
        op += word[word_i]; 
        
        if( op == word)
        {
            ans = 1;
            return;
        }  
         
        for(int i=0 ; i<4 ; i++)
        {
            if(!ans){
              DFS( x+dir[i][0] , y+dir[i][1] , row , col , word_i+1 , word , n , grid , ans , op , visit);
            }
        }
        op.pop_back();
        visit[x][y] = false;
        return;
    }
    bool isWordExist(vector<vector<char>>& grid, string word) {
        // Code here
        int n = word.size();
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visit(row , vector<bool>(col,0));
        bool ans = false;
        string op;
        
        for(int i=0 ; i<row ; i++)
        {
            for(int j=0 ; j<col ; j++)
            {
                if(grid[i][j] == word[0]){
                    DFS(i , j , row , col , 0 , word , n , grid , ans , op , visit);
                     if(ans)
                       return ans;
                }
            }
        }
        return ans;
    }