long long solve(int a , int b)
    {
        if(b==0)
           return 1;
        if(b==1)
           return a;
         
        long long temp = solve(a , b/2) % mod;
        temp = (temp * temp)%mod;
        
        if( b% 2 == 0)
           return temp;
        return (temp*a)%mod;
    }
    
    long long power(int N,int R)
    {
       //Your code here
       return solve(N,R);
        
    }