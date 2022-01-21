int isValid(vector<vector<int>> mat){
        // code here
        int visit[10] = {0};
        
        //row
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                if(mat[i][j] == 0)
                    continue;
                    
                if(visit[mat[i][j]])
                    return 0;
                visit[mat[i][j]] = 1;
            }
            
            for(int i=0 ; i<10 ; i++)
                visit[i] = 0;
        }
        
        //column
        for(int i=0 ; i<9 ; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                if(mat[j][i] == 0)
                    continue;
                
                if(visit[mat[j][i]])
                    return 0;
                visit[mat[j][i]] = 1;
            }
            
            for(int i=0 ; i<10 ; i++)
                visit[i] = 0;
        }
       
        for(int i=0 ; i<10 ; i++)
                visit[i] = 0;
        //3*3
       
        int rs=0 , re = 3 , cs = 0 , ce = 3;
        
        while( 1 )
        {
            int i , j;
            for( i = rs ; i<re ; i++)
            {
                for( j=cs ; j<ce ; j++)
                {
                    if(mat[i][j] == 0)
                       continue;
                       
                    if(visit[mat[i][j]])
                       return 0;
                    visit[mat[i][j]] = 1;
                }
            }
            
            for(int i=0 ; i<10 ; i++)
              visit[i] = 0;
              
            cs = ce;
            ce = cs+3;
            if(cs == 9 && re!=9)
            {
                rs = re;
                re = rs+3;
                cs = 0;
                ce = cs+3;
            }
            else if(cs==9 && re==9)
            {
                return 1;
            }
        }
    }