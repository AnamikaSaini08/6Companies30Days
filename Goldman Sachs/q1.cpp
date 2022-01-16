vector<vector<string> > Anagrams(vector<string>& str) {
        //code here
        int n = str.size();
        bool store[n] = {false};
        vector<vector<string> > ans(n);
        int ind = 0;
        
        for(int i = 0 ; i< n ; i++)
        {
             map<char,int>mp;
             
             if(store[i] == false)
             {
                 store[i] = true;
                 ans[ind].push_back(str[i]);
                 
                 for(int j=0 ; str[i][j] ; j++)
                 {
                     mp[str[i][j]]++;
                 }
             }
             
             else{
                 continue;
             }
             
             for(int j=i+1 ; j<n ; j++)
             {
                 string temp;
                 
                 if(store[j] )
                      continue;
                      
                 map<char , int> mp2;
                 for(int k=0 ; str[j][k]; k++)
                 {
                     mp2[str[j][k]]++;
                 }
                 
                 if(mp==mp2)
                 {
                     store[j] = true;
                     temp+=str[j];
                     ans[ind].push_back(temp);
                 }
                 
             }
             ind++;
        }
        
        for(int i=ans.size()-1 ; i>=0 ; i--)
        {
            if(ans[i].size() == 0)
               ans.pop_back();
            else
               break;
        }
        return ans;
    }