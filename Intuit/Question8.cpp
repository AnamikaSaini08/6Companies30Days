int numberOfBoomerangs(vector<vector<int>>& points) {
        
         int n = points.size() , boom=0 ;
        
        for(int i=0 ; i<n ; i++)
        {
            unordered_map<int,int>mp;
            for(int j=0 ; j<n ; j++)
            {
                if( i == j )
                    continue;
                
                int a = points[i][0];
                int b = points[i][1];
                
                int x = points[j][0];
                int y = points[j][1];
                
                int dis = (a-x)(a-x) + (b-y)(b-y);
                mp[dis]++;
            }
            //nPr for r==2 ->  n*(n-1)
           for(auto ans : mp)
           {
               if(ans.second <2)
                   continue;
               boom += (ans.second * (ans.second-1));
           }
        }
        return boom;
    }