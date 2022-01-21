int solve(int i , int D , int k)
    {
        if(i>D)
           return INT_MAX;
           
        if( i< (-D))
           return INT_MAX;
           
        if(i == D)
           return k;
           
      //  if(dp[i]!=-1)
       //    return dp[i];
        k++; 
        return   min(solve(i-k, D , k) , solve(i+k ,D , k));
    }
    int minSteps(int D){
        // code here
       // memset(dp,-1,sizeof(dp));
       return solve(0 , D , 0);
    }