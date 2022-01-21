void insert(int u , int v , vector<int>graph[])
    {
        graph[u].push_back(v);
    }
    
  void DFS(bool &cycle,int src , vector<int>&rec ,  vector<int>&visit , vector<int> adj[])
  {
      visit[src] = 1;
      rec[src] = 1;
      for(auto nbr : adj[src])
      {
          if(!visit[nbr])
          {
              DFS(cycle,nbr , rec , visit , adj);
          }
          else{
              if(rec[nbr] !=-1)
                  cycle = true;
          }
      }
     rec[src] = -1;
  }
    
	bool isPossible(int N, vector<pair<int, int> >& arr) {
	    // Code here
	    int n = arr.size();
	    vector<int>graph[10005];
	    
	    for(int i=0 ; i<n ; i++)
	    {
	        int v = arr[i].first;
	        int u = arr[i].second;
	        insert(u , v , graph);
	    }
	    
	  vector<int>visit(10005 , 0);
	  vector<int>rec(10005 , -1);
	   bool cycle = false;
	   
	   for(int i=0 ; i<10005 ; i++)
	   {
	       if(!visit[i])
	       {
	           if(!visit[i])
                   DFS(cycle,i , rec , visit , graph);
	       }
	   }
	    return (!cycle);
	}