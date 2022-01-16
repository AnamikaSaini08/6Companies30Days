int countSubArrayProductLessThanK(const vector<int>& v, int n, long long k) {
        
        long long prod = 1 ;
        int i = 0 , j=0 , ans=0;
        
        while(j < n)
        {
            prod = prod * v[j];
            
            while(prod >=k)
            {
                while( i<=j  && prod >=k)
                {
                    prod = prod / v[i];
                    i++;
                }
            }
            
            ans += j-i+1;
            j++;
        }
        return ans;
    }