int dp[10005];
    int solve(int arr[] , int i , int n)
    {
        if(i >= n)
        {
            return 0;
        }
        if(dp[i]!=-1)
           return dp[i];
        
        return dp[i] = max( (arr[i] + solve(arr ,i+2 , n )) , solve(arr, i+1 , n) );
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n == 0)
           return 0;
        if(n==1)
           return arr[0];
        memset(dp,-1,sizeof(dp));
        int m1 = solve(arr , 0 , n );
        int m2 = solve(arr , 1 , n );
        return max(m1,m2);
    }