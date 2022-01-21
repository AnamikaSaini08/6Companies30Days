class Solution {
  public:

   int dp[505][2][205];
     int solve(int i , bool own,int prices[],int k,int n )
    {
        if(i >= n || k==0)
            return 0;

        if(dp[i][own][k]!=-1)
            return dp[i][own][k];

        if(own)
            return dp[i][own][k] = max( (prices[i] + solve(i+1 ,false, prices , k-1,n) ) ,solve(i+1 ,true,prices,k,n) );

        else
            return dp[i][own][k] = max((-(prices[i])+ solve(i+1,true, prices,k,n) ) ,solve(i+1 ,false,prices,k,n) );
    }

    int maxProfit(int K, int n, int prices[]) {
        // code here
        memset(dp , -1 , sizeof(dp));
        return solve( 0 , false , prices,K,n);
    }