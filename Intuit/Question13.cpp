int minSwaps(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int>trailing_zero;
        
        
        //trailing zero in each row
        for(int i= 0; i<n ; i++)
        {
            int trail_zero = 0;
            
            for(int j=m-1 ;j>=0 ; j--)
            {
                if(!grid[i][j])
                    trail_zero++;
                else{
                    break;
                }
            }
            trailing_zero.push_back(trail_zero);
        }
        
        int size = trailing_zero.size();
        
        //No of swaps in bubble sort
        int swap_no = 0;
        
        for(int i=0 ; i<size ; i++)
        {
            int target = n - i - 1;
            if(trailing_zero[i] >= target)
                continue;
            
            int j = i+1;
            while( j<n && trailing_zero[j] < target)
                j++;
            
            if(j==n)
                return -1;
            
            while( j > i )
            {
               swap( trailing_zero[j] , trailing_zero[j-1]);
                j--;
                swap_no++;
            }
        }
        return swap_no;
    }