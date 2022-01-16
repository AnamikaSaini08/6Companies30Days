long long dp[10005];
	long long mod = 1000000007;
	    long long solve(long long i , long long n , string str)
	    {
	           
	        if(str[i] == '0')
	            return 0;
	       
	        if(i >= n)
	            return 1;
	        
	        if(i == n-1)
	        {
	            if(str[i] == '0')
	               return 0;
	             return 1;
	        }
	        
	        if(dp[i] != -1)
	           return dp[i];
	        
	        long long a = str[i] - 48;
	        long long b = str[i+1] - 48;
	        
	        if( (a*10 + b) <= 26){
	            
	            if(b==0)
	                return dp[i] = solve(i+2 , n , str) % mod;
	            else
	                return dp[i] =  ( (solve(i+1 ,  n, str)%mod) + (solve(i+2 , n , str)%mod) )%mod ;
	        }
	        
	        else{
	            if(b==0)
	               return 0;
	            else
	               return dp[i] = solve(i+1 , n ,str) % mod;
	        }
	        
	        
	    }
		long long CountWays(string str){
		    // Code here
		    memset(dp,-1,sizeof(dp));
		    return solve(0 , str.size() , str);
		}