class Solution {
public:
    unordered_map<int, unordered_map<int, int>> dp;
    
    int getMoneyAmount(int n) {
        
        return rec(1, n);
    }
    
    int rec(int l, int h) {
        
        if(l >= h) 
            return 0;
        if(dp[l].count(h)) 
            return dp[l][h];
        int ret = INT_MAX;
        
        for(int i = l ; i <= h ; i++) {
            
            int temp = i + max(rec(l, i - 1), rec(i + 1, h));
            ret = min(ret, temp);
        }
        
        return dp[l][h] = ret;
    }
};