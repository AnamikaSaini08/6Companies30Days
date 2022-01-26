int lengthOfLongestAP(int A[], int n) {
        // code here
        if( n<=2)
          return n;
          
        vector<unordered_map<int,int>>dp(n);
        int max_len = 2;
        
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<i ; j++)
            {
                int diff = A[j] - A[i];
                if(dp[i].find(diff) != dp[i].end())
                {
                    dp[j][diff] = dp[i][diff] + 1;
                }
                else{
                    dp[j][diff] = 2;
                }
                max_len = max(max_len , dp[j][diff]);
            }
        }
        return max_len;
    }