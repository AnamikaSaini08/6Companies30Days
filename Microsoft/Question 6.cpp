void solve(int a[] , int n, int i ,  map<int , string>&mp ,string sb , vector<string>&res )
    {
        if(sb.length() == n)
        {
            res.push_back(sb);
            return;
        }
        
        string currEle = mp[a[i]];
        
        for(int j= 0; currEle[j] ; j++)
        {
            sb+=(currEle[j]);
            solve(a , n , i+1 , mp , sb , res);
            sb.pop_back();
        }
    }
    
    
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string>ans;
        
        if(n==0)
           return ans;
           
        map<int , string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7]= "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        string temp;
        solve(a , n , 0 , mp , temp , ans);
        return ans;
    }