bool solve(int arr[] , int n , int sum)
    {
        int dp[n+1][sum+1];
        
        for(int i=0 ; i<=n ; i++)
        {
            for(int j =0 ; j<=sum ; j++)
            {
                if(j == 0)
                  dp[i][j] =  1;
                  
                else if(i ==0 )
                  dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=sum ; j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0 ; i<N ; i++)
        {
            sum += arr[i];
        }
        
        if(sum % 2 !=0)
          return 0;
        
        return solve(arr , N , sum/2);
    }