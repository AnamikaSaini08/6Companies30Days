string colName (long long int n)
    {
        // your code here
        string res;
        
        while(n)
        {
            char ch = 'A' + (n-1)%26;
            res += ch;
            n = (n-1)/26;
        }
        reverse(res.begin() , res.end());
        return res;
    }