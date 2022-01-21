vector<int> isPair(int i , int n , int x , vector<int>&arr)
    {
        long long left = i;
        long long right = n-1;
        vector<int>v;
        
        while(left < right)
        {
            long long sum = arr[left]+arr[right];
            
            if(sum == x)
             {
                 v.push_back(arr[left]);
                 v.push_back(arr[right]);
                 return v;
             }
              
            if( sum > x)
            {
                right--;
            }
            else{
                left++;
            }
        }
        return v;
    }
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here'
      sort(arr.begin() , arr.end());
      vector<vector<int>>ans;
      int n=arr.size();
      for(int i=0 ; i<n-1 ; i++)
      {
          for(int j=i+1 ; j<n ; j++)
          {
              vector<int>res = isPair(j+1 , n , k-arr[i]-arr[j] , arr);
              if(res.size())
              {
                  res.push_back(arr[i]);
                  res.push_back(arr[j]);
                  ans.push_back(res);
              }
          }
      }
      for(int i=0 ; i<ans.size() ; i++)
         sort(ans[i].begin() , ans[i].end());
      sort(ans.begin(),ans.end());
         return ans;
    }