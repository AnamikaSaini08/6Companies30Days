bool canPair(vector<int> arr, int k)
    {
        unordered_map<int,int>mp;
       
        int n = arr.size();
        
        for(int i=0 ; i<n ; i++)
        {
            mp[arr[i]%k]++;
        }
        
        
        for(auto temp : mp)
        {
            int a = temp.first;
            int b = k-a;
            
            if(a == 0)
            {
                if(mp[a] % 2 !=0 )
                    return false;
            }
            
            else if( a == b)
            {
                if(mp[a] % 2 !=0)
                   return false;
            }
            
            else if(mp.find(b) != mp.end())
            {
                if(mp[b] != mp[a])
                   return false;
                
            }
            else
              return false;
        }
       return true;
    }