long long dp[1005][1005];
    long long m = 1000000007;
    public:
    long long power(long long i , long long x)
    {
        long long res = 1;
        for(long long j=1 ; j<=x;  j++)
        {
            res *= i;
        }
        return res;
    }
    
    long long  solve( long long i , long long n , long long x , long long res )
    {
        if(res == n)
            return 1;
        
        if(res > n)
           return 0;
           
         if(i > n)
           return 0;
        
        if(dp[i][res] !=-1)
           return dp[i][res];
        
        long long temp = pow(i , x);
          
        return dp[i][res] = ((solve(i+1 , n, x , res+temp))%m + (solve(i+1 , n , x , res))%m)%m;
    }
    
    long long int numOfWays(int n, int x)
    {
        // code her
        memset(dp,-1,sizeof(dp));
        return solve(1 , n , x , 0 );
    }