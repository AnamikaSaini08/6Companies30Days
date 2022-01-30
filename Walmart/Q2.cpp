class Solution {
public:
    int dp[501][501];
    int solve( int i , int j , vector<int>&piles)
    {
        if( i == j)
            return piles[i];
        
        if( i+1 == j )
            return max(piles[i],piles[j]);
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a = piles[i] + min(solve(i+2 , j , piles) , solve(i+1 , j-1 , piles ) );
        int b = piles[j] + min( solve(i , j-2 , piles) , solve(i+1 , j-1 , piles));
        
        return dp[i][j] = max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        int sum = 0;
        for(int i=0 ; i<n ; i++)
            sum += piles[i];
        sum /= 2;
        
        int t =  solve( 0 , n-1 , piles);
        if(t > sum)
            return 1;
        return 0;
    }
};