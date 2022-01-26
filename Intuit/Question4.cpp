void solve(int ind , int n , string &ans , string str, int k)
    {
        if( k==0 )
           return;
           
        char maxchar = str[ind];
        for(int i=ind+1 ; i<n ; i++)
        {
            if(maxchar < str[i])
               maxchar = str[i];
        }
        
        if(maxchar != str[ind])
          k--;
        
        for(int i = n-1 ; i>=ind ; i--)
        {
            if(str[i] == maxchar)
            {
                swap(str[ind] , str[i]);
                if(ans < str)
                   ans = str;
                
                solve(ind+1 , n ,ans ,str , k);
                swap(str[ind] , str[i]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(0 , str.size() , ans ,str, k );
       return ans;
    }