void DFS(bool &ans ,int src, int par , int visit[] , int low[] , int tm[] , vector<int>adj[] , int c , int d , int timer)
    {
        visit[src] = 1;
        low[src] = tm[src] = timer++;
        
        for(auto nbr : adj[src])
        {
            if(nbr == par)
               continue;
               
            if(!visit[nbr])
            {
                DFS(ans ,nbr , src , visit , low , tm , adj , c , d , timer);
                low[src] = min(low[src] , low[nbr]);
                
                if(low[nbr] > tm[src])
                {
                    if( (c== nbr and src == d) || (c==src and nbr == d))
                        ans = true;
                }
            }
            else{
                low[src] = min(low[src],tm[nbr]);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code 
        int vis[V] = {0};
        int low[V] = {0};
        int tm[V] = {0};
        bool ans=  false;
        int timer = 1;
        
        for(int i=0 ; i<V ; i++)
        {
            if(!vis[i])
            {
                 DFS(ans , i , -1 , vis , low , tm , adj , c, d , timer);
            }
        }
        return ans;
    }