class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>>V;
        
        for(int i=0; i<n; i++)
            V.push_back({efficiency[i], speed[i]});
        
        sort(V.begin(), V.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        
        
        priority_queue<int>pq;
        long long speedd = 0, ans = 0;
        
        
        for(auto it:V)
        {
            speedd += it.second;
            
            pq.push(-it.second);
            
            if(pq.size() > k)
            {
                speedd -= abs(pq.top());
                pq.pop();
            }
            
            ans = max(ans, it.first*speedd);
        }
        
        return ans % 1000000007;
    }
};