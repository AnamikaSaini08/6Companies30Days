void make_graph(int u , int v , vector<int>adj[])
    {
        adj[u].push_back(v);
    }
    
    void IsFinishCourse(int src , vector<int>&visit , vector<int>&rec , vector<int>adj[] , bool &cycle , vector<int>&ans)
    {
        visit[src] = 1;
        rec[src] = 1;
       
        for( auto nbr : adj[src])
        {
            if(!visit[nbr])
            {
                IsFinishCourse( nbr , visit , rec , adj , cycle , ans);
            }
            else{
                if(rec[nbr])
                {
                    cycle = true;
                    return;
                }
            }
        }
        rec[src] = 0;
        ans.push_back(src);
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        
        int n = prerequisites.size();
        
        vector<int>visit(numCourses,0);
        vector<int>rec(numCourses,0);
        vector<int>ans;
        
        for(int i=0 ; i<n ; i++)
        {
            make_graph(prerequisites[i][1] , prerequisites[i][0] , adj);
        }
        
        bool cycle = false;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(!visit[i])
            {
                IsFinishCourse(i , visit , rec , adj , cycle , ans);
            }
        }
       
        if(cycle)
        {
            vector<int>ans;
            return ans;
        }
        reverse(ans.begin() , ans.end());
        return ans;
        
    }