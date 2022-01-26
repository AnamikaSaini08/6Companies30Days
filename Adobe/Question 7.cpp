int dp[505][505];
    int solve(int i , int j , vector<int>&arr)
    {
        if(i == j)
           return arr[i];
        if(i+1 == j)
           return max(arr[i],arr[j]); 
           
        if(dp[i][j] !=-1)
          return dp[i][j];
          
        int start = arr[i] + min( solve(i+2 , j , arr) , solve(i+1 , j-1 , arr));
        int end = arr[j] + min( solve(i+1 , j-1 , arr) , solve(i , j-2 , arr));
        
        return dp[i][j] = max(start , end);
    }
    int maxCoins(vector<int>&arr,int n)
    {
	    //Write your code here
	    memset(dp, -1, sizeof(dp));
	    return solve(0 , n-1 , arr);
    }