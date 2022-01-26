string nextPalin(string str) { 
        //complete the function here
        int n = str.size();
        if(n <= 3)
          return "-1";
        
        int mid = n/2 - 1;
        int ind1 = -1 , ind2;
        
        for(int i = mid-1 ; i>=0 ; i--)
        {
            if(str[i] < str[i+1])
            {
                ind1 = i;
                break;
            }
        }
        
        if(ind1 == -1)
            return "-1";
            
        for( int i = mid ; i>ind1 ; i--) 
        {
            if(str[i] > str[ind1])
            {
                ind2 = i;
                break;
            }
        }
        
        swap(str[ind1] , str[ind2]);
        
        swap(str[n-ind1-1] , str[n-ind2-1]);
        
        reverse(str.begin()+ind1+1 , str.begin()+mid+1);
        
        if( n% 2 == 0)
           reverse(str.begin() + mid+1 , str.begin()+n-ind1-1);
        else
           reverse(str.begin() + mid+2 , str.begin()+n-ind1-1);
        return str;
    }