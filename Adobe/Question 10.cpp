vector<string> winner(string arr[],int n)
    {
        unordered_map<string , int>mp;
        vector<string>ans;
        
        for(int i=0 ; i<n ; i++)
        {
            mp[arr[i]]++;
        }
        
        string key;
        int value = 0;
       
       for(auto temp: mp)
       {
           string str = temp.first;
           int num = temp.second;
           
           if(num > value)
           {
               key = str;
               value = num;
           }
           else if(num == value)
           {
               if(str < key)
                 key = str;
           }
       }
        ans.push_back(key);
        string temp = to_string(value);
        ans.push_back(temp);
        return ans;
        
        
    }