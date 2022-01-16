long long arr[10005];
	
	void preCompute()
	{
	    long long i2 = 0 , i3 = 0 , i5 = 0 , ind = 1;
	    long long p2 , p3 , p5;
	    arr[0] = 1;
	   
	    for(long long i=2 ; i<10005 ; i++)
	    {
	        p2 = arr[i2] * 2;
	        p3 = arr[i3] * 3;
	        p5 = arr[i5] * 5;
	        
	        long long res = min( {p2 , p3 , p5});
	        arr[ind] = res;
	        
	        if(arr[ind] == p2)
	            i2++;
	            
	        if(arr[ind] == p3)
	           i3++;
	           
	        if(arr[ind] == p5)
	           i5++;
	           
	        ind++;
	    }
	}
	
	ull getNthUglyNo(int n) {
	    // code here
	    preCompute();
	    return arr[n-1];
	}