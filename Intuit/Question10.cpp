void CountProvince(int src , vector<int>&visit , vector<vector<int>>& isConnected , int n)
    {
        if(visit[src])
            return;
        
        visit[src] = 1;
       
        for(int i = 0 ; i<n ; i++)
        {
            if( i == src)
              continue;
                
            if(isConnected[src][i])
            {
                    //isConnected[i][j] = 0;
                if(visit[src])
                    CountProvince( i , visit , isConnected , n);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int>visit(n , 0);
        
        int no_of_prov = 0;
        
        for(int i=0 ; i<n ; i++)
        {
            if(!visit[i])
            {
                CountProvince( i , visit , isConnected , n);
                no_of_prov += 1;
            }
        }
        return no_of_prov;
        
    }