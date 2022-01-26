int LIS(vector<int>arr)
  {
      vector<int>ans;
      
      int n = arr.size();
      if(!n)
        return 0;
        
      ans.push_back(arr[0]);
      
      for(int i=1 ; i<n ; i++)
      {
          if(arr[i] > ans.back())
             ans.push_back(arr[i]);
          
          int ind = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin();
          ans[ind] = arr[i];
      }
      return ans.size();
  }
    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        vector<int>rest;
        for(int i=0 ; i<n ; i++)
        {
            if(binary_search(b , b+m , a[i]))
            {
                rest.push_back(a[i]);
            }
        }
        return (n+m-(2*LIS(rest)));
    }