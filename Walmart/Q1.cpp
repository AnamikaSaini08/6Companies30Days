class Solution {
public:
    typedef pair<double,int> data;
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
        
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<data> q;
        vector<double> vt(n,0);
        vt[start] = 1;
        q.push({1.0,start});
        while(!q.empty())
        {
            int u = q.top().second;
            q.pop();
            for(auto v:graph[u])
            {
                double p = v.second;
                int node = v.first;
                if(vt[node] < vt[u]*p)
                {
                    vt[node] = vt[u]*p;
                    q.push({vt[u]*p,node});
                }
            }
        }
        return vt[end];
    }
};